<?php
require './vendor/autoload.php';
$f3 = \Base::instance();
$f3->config('./app/configs/config.ini');
$f3->set('DB', new \DB\SQL(
    $f3->get('db.dsn'),
    $f3->get('db.username'),
    $f3->get('db.password')
));
$f3->run();

$f3->set('ONERROR', function($f3) {
    $error = $f3->get('ERROR');

    error_log("[{$error['code']}] {$error['text']} in {$error['file']} on line {$error['line']}");

    if ($f3->get('DEBUG')) {
        echo "<h1>{$error['status']}</h1>";
        echo "<p>{$error['text']}</p>";
        echo "<pre>{$error['trace']}</pre>";
    } else {
        echo "<h1>Oops! Something went wrong.</h1>";
        echo "<p>Please try again later.</p>";
    }
    
    exit;
});