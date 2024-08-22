# Rust Token Management Server

Simple token management server built using Rust, Warp for the web framework, SQLx for interacting with an SQLite database, and Serde for serialization and deserialization of JSON data. The server supports basic operations such as adding tokens and checking their validity.

### Requirements
- Rust *(if not installed, click [here](https://www.rust-lang.org/learn/get-started))*
- Sqlite3 *(if not installed, click [here](https://www.sqlite.org/download.html))*

### Installation

1. install the dependencies and build the project:
    ```sh
    cargo build
	```

### Database setup

1. create an sqlite db named `tokens.sqlite3`:
    ```bash
    sqlite3 tokens.sqlite3
    ```

2. create the `tokens` table:
    ```sql
    CREATE TABLE tokens (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        token TEXT NOT NULL
    );
    .exit
    ```


### Running the server

to run the server, simply use:
```sh
cargo run
```
