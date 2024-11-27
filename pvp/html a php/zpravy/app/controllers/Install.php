<?php

namespace controllers;

use models\Uzivatel;
use models\Zpravy;
use models\Soubor;
use models\Login;

class Install extends AbstractController
{
    private function nastavRole($pole)
    {
        foreach ($pole as $r) {
            $role = new \models\Role();
            $role->nazev = $r['nazev'];
            $role->popis = $r['popis'];
            $role->save();
            unset($role);
        }
    }

    public function setup_uzivatel() {
        \models\Uzivatel::setdown(); // drop table pokud existuje
        \models\Uzivatel::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function setup_zpravy() {
        \models\Zpravy::setdown(); // drop table pokud existuje
        \models\Zpravy::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function setup_soubory() {
        \models\Soubor::setdown(); // drop table pokud existuje
        \models\Soubor::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function setup_login() {
        \models\Login::setdown(); // drop table pokud existuje
        \models\Login::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function setup_role() {
        \models\Role::setdown(); // drop table pokud existuje
        \models\Role::setup(); // vytvoření tabulky
        $this->nastavRole([ // vytvoření admin role
            ['nazev'=>'admin','popis'=>'Administrátor'],
            ['nazev'=>'user','popis'=>'Uživatel'],
            ['nazev'=>'guest','popis'=>'Návštevník']
        ]);
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