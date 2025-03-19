<?php

namespace controllers;

use models\Index;

class Install
{
    public function instalace_uzivatele() {
        \models\Uzivatele::setdown(); // drop table pokud existuje
        \models\Uzivatele::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_recenze() {
        \models\Recenze::setdown(); // drop table pokud existuje
        \models\Recenze::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_produkty() {
        \models\Produkty::setdown(); // drop table pokud existuje
        \models\Produkty::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function vsechno() {
        \models\Uzivatele::setdown(); // drop table pokud existuje
        \models\Uzivatele::setup(); // vytvoření tabulky
        
        \models\Recenze::setdown(); // drop table pokud existuje
        \models\Recenze::setup(); // vytvoření tabulky
        
        \models\Produkty::setdown(); // drop table pokud existuje
        \models\Produkty::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }
} 