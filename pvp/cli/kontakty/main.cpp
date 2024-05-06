#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <sqlite3.h>

using namespace std;

class Kontakt
{
public:
    string jmeno;
    string telefonniCislo;
    string email;

    Kontakt(const string &jmeno, const string &telefonniCislo, const string &email)
        : jmeno(jmeno), telefonniCislo(telefonniCislo), email(email) {}
};

class Kontakty
{
private:
    vector<Kontakt> kontakty;
    sqlite3 *databaze;

public:
    Kontakty()
    {
        int returnCode = sqlite3_open("kontakty.db", &databaze);
        if (returnCode)
        {
            cerr << "<> pri otevirani databaze nastala chyba: " << sqlite3_errmsg(databaze) << endl;
            exit(1);
        }

        char *errorMessage;
        const char *sql = "CREATE TABLE IF NOT EXISTS kontakty ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "jmeno TEXT NOT NULL,"
                          "telefonniCislo TEXT NOT NULL,"
                          "email TEXT NOT NULL);";

        returnCode = sqlite3_exec(databaze, sql, nullptr, nullptr, &errorMessage);
        if (returnCode != SQLITE_OK)
        {
            cerr << "<> sql error: " << errorMessage << endl;
            sqlite3_free(errorMessage);
            exit(1);
        }
    }

    ~Kontakty()
    {
        sqlite3_close(databaze);
    }

    void vytvoritKontakt(const string &jmeno, const string &telefonniCislo, const string &email)
    {
        Kontakt kontakt(jmeno, telefonniCislo, email);
        kontakty.push_back(kontakt);

        string sql = "INSERT INTO kontakty (jmeno, telefonniCislo, email) VALUES (?, ?, ?);";
        sqlite3_stmt *pripraveny_statement;
        int returnCode = sqlite3_prepare_v2(databaze, sql.c_str(), -1, &pripraveny_statement, nullptr);
        if (returnCode != SQLITE_OK)
        {
            cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
            return;
        }

        sqlite3_bind_text(pripraveny_statement, 1, jmeno.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(pripraveny_statement, 2, telefonniCislo.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(pripraveny_statement, 3, email.c_str(), -1, SQLITE_STATIC);

        returnCode = sqlite3_step(pripraveny_statement);
        if (returnCode != SQLITE_DONE)
        {
            cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
        }

        sqlite3_finalize(pripraveny_statement);
    }

    void odebratKontakt(const string &jmeno)
    {
        auto iterator = find_if(kontakty.begin(), kontakty.end(), [&](const Kontakt &kontakt)
                                { return kontakt.jmeno == jmeno; });

        if (iterator != kontakty.end())
        {
            kontakty.erase(iterator);
            cout << "<> kontakt byl odebran." << endl;

            string sql = "DELETE FROM kontakty WHERE jmeno = ?;";
            sqlite3_stmt *pripraveny_statement;
            int returnCode = sqlite3_prepare_v2(databaze, sql.c_str(), -1, &pripraveny_statement, nullptr);
            if (returnCode != SQLITE_OK)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
                return;
            }

            sqlite3_bind_text(pripraveny_statement, 1, jmeno.c_str(), -1, SQLITE_STATIC);

            returnCode = sqlite3_step(pripraveny_statement);
            if (returnCode != SQLITE_DONE)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
            }

            sqlite3_finalize(pripraveny_statement);
        }
        else
        {
            cout << "<> kontakt nebyl nalezen." << endl;
        }
    }

    void upravitKontakt(const string &jmeno, const string &noveTelefonniCislo, const string &novyEmail)
    {
        auto iterator = find_if(kontakty.begin(), kontakty.end(), [&](const Kontakt &kontakt)
                                { return kontakt.jmeno == jmeno; });

        if (iterator != kontakty.end())
        {
            iterator->telefonniCislo = noveTelefonniCislo;
            iterator->email = novyEmail;
            cout << "<> kontakt byl upraven." << endl;

            string sql = "UPDATE kontakty SET telefonniCislo = ?, email = ? WHERE jmeno = ?;";
            sqlite3_stmt *pripraveny_statement;
            int returnCode = sqlite3_prepare_v2(databaze, sql.c_str(), -1, &pripraveny_statement, nullptr);
            if (returnCode != SQLITE_OK)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
                return;
            }

            sqlite3_bind_text(pripraveny_statement, 1, noveTelefonniCislo.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(pripraveny_statement, 2, novyEmail.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(pripraveny_statement, 3, jmeno.c_str(), -1, SQLITE_STATIC);

            returnCode = sqlite3_step(pripraveny_statement);
            if (returnCode != SQLITE_DONE)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
            }

            sqlite3_finalize(pripraveny_statement);
        }
        else
        {
            cout << "<> kontakt nebyl nalezen." << endl;
        }
    }

    void najitKontakt(const string &jmeno)
    {
        auto iterator = find_if(kontakty.begin(), kontakty.end(), [&](const Kontakt &kontakt)
                                { return kontakt.jmeno == jmeno; });

        if (iterator != kontakty.end())
        {
            cout << ">> Jmeno: " << iterator->jmeno << endl;
            cout << ">> Telefonni cislo: " << iterator->telefonniCislo << endl;
            cout << ">> Email: " << iterator->email << endl;
        }
        else
        {
            sqlite3 *databaze;
            int returnCode = sqlite3_open("kontakty.db", &databaze);
            if (returnCode != SQLITE_OK)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
                return;
            }

            string sql = "SELECT * FROM kontakty WHERE jmeno = ?;";
            sqlite3_stmt *pripraveny_statement;
            returnCode = sqlite3_prepare_v2(databaze, sql.c_str(), -1, &pripraveny_statement, nullptr);
            if (returnCode != SQLITE_OK)
            {
                cerr << "<> sqlite error: " << sqlite3_errmsg(databaze) << endl;
                sqlite3_close(databaze);
                return;
            }

            sqlite3_bind_text(pripraveny_statement, 1, jmeno.c_str(), -1, SQLITE_STATIC);

            returnCode = sqlite3_step(pripraveny_statement);
            if (returnCode == SQLITE_ROW)
            {
                string jmeno = reinterpret_cast<const char *>(sqlite3_column_text(pripraveny_statement, 0));
                string telefonniCislo = reinterpret_cast<const char *>(sqlite3_column_text(pripraveny_statement, 1));
                string email = reinterpret_cast<const char *>(sqlite3_column_text(pripraveny_statement, 2));

                cout << ">> Jmeno: " << jmeno << endl;
                cout << ">> Telefonni cislo: " << telefonniCislo << endl;
                cout << ">> Email: " << email << endl;
            }
            else
            {
                cout << "<> kontakt nebyl nalezen." << endl;
            }

            sqlite3_finalize(pripraveny_statement);
            sqlite3_close(databaze);
        }
    }
};

int main()
{
    Kontakty kontakty;

    int moznost;
    string jmeno, telefonniCislo, email;

    do
    {
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        cout << "<|>        kontakty       <|>" << endl
             << endl;
        cout << "   1)  pridat kontakt" << endl;
        cout << "   2)  odebrat kontakt" << endl;
        cout << "   3)  upravit kontakt" << endl;
        cout << "   4)  vyhledat kontakt" << endl;
        cout << "   5)  odejit" << endl
             << endl;
        cout << "-> ";
        cin >> moznost;

        switch (moznost)
        {
        case 1:
            cout << ">< jmeno?" << endl;
            cout << "=> ";
            cin.ignore();
            getline(cin, jmeno);
            cout << ">< telefonni cislo?" << endl;
            cout << "=> ";
            cin >> telefonniCislo;
            cout << ">< email?" << endl;
            cout << "=> ";
            cin >> email;
            kontakty.vytvoritKontakt(jmeno, telefonniCislo, email);
            break;
        case 2:
            cout << ">< jmeno?" << endl;
            cout << "=> ";
            cin.ignore();
            getline(cin, jmeno);
            kontakty.odebratKontakt(jmeno);
            break;
        case 3:
            cout << ">< jmeno?" << endl;
            cout << "=> ";
            cin.ignore();
            getline(cin, jmeno);
            cout << ">< nove telefonni cislo?" << endl;
            cout << "=> ";
            cin >> telefonniCislo;
            cout << ">< novy email?" << endl;
            cout << "=> ";
            cin >> email;
            kontakty.upravitKontakt(jmeno, telefonniCislo, email);
            break;
        case 4:
            cout << ">< jmeno?" << endl;
            cout << "=> ";
            cin.ignore();
            getline(cin, jmeno);
            kontakty.najitKontakt(jmeno);
            break;
        case 5:
            cout << "odchazim..." << endl;
            break;
        default:
            cout << "neplatna moznost, zkus znovu." << endl;
            break;
        }

        cout << endl;

    } while (moznost != 5);

    return 0;
}
