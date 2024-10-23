<?php
echo '<!DOCTYPE html>
<html lang="cs">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Přihlášení</title>
    <style>
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            font-family: \'Segoe UI\', Tahoma, Geneva, Verdana, sans-serif;
            background-color: #f0f2f5;
        }
        
        form {
            background: #fff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            width: 100%;
            max-width: 400px;
        }
        
        h1 {
            font-family: \'Trebuchet MS\', \'Lucida Sans Unicode\', \'Lucida Grande\', \'Lucida Sans\', Arial, sans-serif;
            text-align: center;
            margin-bottom: 20px;
        }
        
        label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <form>
        <h1>Výsledek přihlášení</h1>';
        echo "<p>Zadané jméno: " . htmlspecialchars($_POST["jmeno"]) . "</p>";
        echo "<p>Zadané heslo: " . htmlspecialchars($_POST["heslo"]) . "</p>";
echo '</form>
</body>
</html>';
?>