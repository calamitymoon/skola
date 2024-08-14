use serde::{Deserialize, Serialize};
use sqlx::sqlite::SqlitePool;
use warp::http::StatusCode;
use warp::Filter;

#[tokio::main]
async fn main() -> Result<(), warp::Rejection> {
    let database_url = "tokens.sqlite3";

    //  connect to db
    let pool = match SqlitePool::connect(database_url).await {
        Ok(pool) => pool,
        Err(e) => {
            eprintln!("Failed to connect to database: {}", e);
            std::process::exit(1);
        }
    };

    //  filter for /secret endpoint
    let secret = warp::path("secret")
        .and(warp::header::optional::<String>("token"))
        .and(with_db(pool.clone()))
        .and_then(handle_secret);

    //  filter for /manage-tokens endpoint
    let manage_tokens = warp::path("manage-tokens")
        .and(warp::post())
        .and(warp::body::json())
        .and(with_db(pool.clone()))
        .and_then(handle_manage_tokens);

    // filter for / root page
    let _root = warp::path::end().map(|| {
        warp::reply::html(
            r#"
            <html>
                <body>
                    <style>
                        .command {
                            background-color: #1e1e1e;
                            color: #00ff00;
                            font-family: "Courier New", Courier, monospace;
                            font-size: 12px;
                            padding: 10px;
                            border-radius: 5px;
                            box-shadow: 0 0 10px rgba(0, 0, 0, 0.5);
                            white-space: pre-wrap;
                            line-height: 1.5;
                        }

                        .command::before {
                            content: "$ ";
                            color: #00ff00;
                        }
                    </style>
                    <pre>
[ check token validity ]
                    </pre>
                    <pre class="command">
curl -H "token: 123" http://localhost:3030/secret
                    </pre>
                    <br>
                    <pre>
[ add token ]
                    </pre>
                    <pre class="command">
curl -X POST http://localhost:3030/manage-tokens \
     -H "Content-Type: application/json" \
     -d '{"token": "123"}'
                    </pre>
                </body>
            </html>
            "#,
        )
    });

    //  warp server
    warp::serve(_root.or(secret).or(manage_tokens))
        .run(([127, 0, 0, 1], 3030))
        .await;

    Ok(())
}

//  db pool to the filter
fn with_db(
    pool: SqlitePool,
) -> impl Filter<Extract = (SqlitePool,), Error = std::convert::Infallible> + Clone {
    warp::any().map(move || pool.clone())
}

//  handler for /secret
async fn handle_secret(
    token: Option<String>,
    pool: SqlitePool,
) -> Result<impl warp::Reply, warp::Rejection> {
    match token {
        Some(ref token) => {
            //  check if token is in db
            let row = sqlx::query("SELECT token FROM tokens WHERE token = ?")
                .bind(token)
                .fetch_one(&pool)
                .await;

            match row {
                Ok(_) => Ok(warp::reply::with_status(
                    "[Authorized] Valid token!",
                    StatusCode::OK,
                )),
                Err(_) => Ok(warp::reply::with_status(
                    "[Unauthorized] Invalid token!",
                    StatusCode::UNAUTHORIZED,
                )),
            }
        }
        None => {
            //  header without 'token'
            Ok(warp::reply::with_status(
                "[Unauthorized] Missing token!",
                StatusCode::UNAUTHORIZED,
            ))
        }
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct TokenRequest {
    token: String,
}

//  handler for /manage-tokens
async fn handle_manage_tokens(
    token_request: TokenRequest,
    pool: SqlitePool,
) -> Result<impl warp::Reply, warp::Rejection> {
    //  add token to db
    let result = sqlx::query("INSERT INTO tokens (token) VALUES (?)")
        .bind(&token_request.token)
        .execute(&pool)
        .await;

    match result {
        Ok(_) => Ok(warp::reply::with_status("[Token] added", StatusCode::OK)),
        Err(e) => {
            eprintln!("[Token] failed to add: {}", e);
            Ok(warp::reply::with_status(
                "[Token] failed to add",
                StatusCode::INTERNAL_SERVER_ERROR,
            ))
        }
    }
}
