# Emailovač

Emailovač je jednoduchý projekt pro resetování hesla pomocí e-mailu. Tento projekt je postaven na frameworku [Fat-Free Framework (F3)](https://fatfreeframework.com/) a obsahuje základní funkce pro registraci, přihlášení, resetování hesla a správu uživatelů.

## Funkce

- **Registrace uživatele**: Uživatelé se mohou registrovat pomocí jména, e-mailu a hesla.
- **Přihlášení uživatele**: Uživatelé se mohou přihlásit pomocí svého jména a hesla.
- **Zapomenuté heslo**: Uživatelé mohou požádat o resetování hesla, přičemž obdrží e-mail s odkazem na reset hesla.
- **Resetování hesla**: Uživatelé mohou nastavit nové heslo pomocí tokenu zaslaného e-mailem.

## Složky a soubory

- **`app/controllers`**: Obsahuje kontrolery pro správu uživatelů, autentizaci a e-mailové operace.
- **`app/models`**: Obsahuje modely pro práci s databázovými tabulkami `uzivatele` a `nove_heslo`.
- **`app/views`**: Obsahuje šablony pro zobrazení uživatelského rozhraní.
- **`app/configs`**: Obsahuje konfigurační soubory pro databázi, směrování a e-mailové nastavení.
- **`index.php`**: Hlavní vstupní bod aplikace.

## Požadavky

- PHP 7.4 nebo novější
- MySQL databáze
- Composer pro správu závislostí

## Instalace

1. Naklonujte tento repozitář:
   ```bash
   git clone https://gitlab.prumkadc.cz/juza.dominik/emailovac.git
   ```
2. Nainstalujte závislosti pomocí Composeru:
   ```bash
   composer install
   ```
3. Nastavte databázi a upravte soubor `app/configs/db.ini` podle vašich potřeb.
4. Spusťte inicializaci databáze:
   - Navštivte `/install` ve vašem prohlížeči.
5. Případně změňte $baseURL ve funkci send_reset_password. Tato URL se používá pro generování resetovacích odkazů, které jsou zasílány uživatelům e-mailem. Ujistěte se, že je nastavena správně na base url Vašeho projektu, aby resetovací odkazy fungovaly jak mají.

## Routy

- Navštivte `/register` pro registraci nového uživatele.
- Navštivte `/login` pro přihlášení.
- Navštivte `/zapomenute-heslo` pro resetování hesla.

## Konfigurace e-mailu

E-mailové nastavení je definováno v souboru `app/configs/mailer.ini`. Upravte hodnoty podle vašeho SMTP serveru.

## Licence

Tento projekt je licencován pod licencí MIT.
