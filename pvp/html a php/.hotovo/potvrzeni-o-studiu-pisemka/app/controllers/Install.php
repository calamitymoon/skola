<?php

namespace controllers;

use models\Index;

class Install
{
    public function instalace_uzivatelu() {
        \models\User::setdown(); // drop table pokud existuje
        \models\User::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_potvrzeni() {
        \models\Potvrzeni::setdown(); // drop table pokud existuje
        \models\Potvrzeni::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function index(\Base $base)
    {
        $f3 = \Base::instance();
        $f3->config('./app/configs/config.ini');
        $f3->config('./app/configs/routes.ini');
        
        $f3->set('DB', new \DB\SQL(
            $f3->get('db.dsn'),
            $f3->get('db.username'),
            $f3->get('db.password')
        ));
        
        $f3->run();
    }
} 