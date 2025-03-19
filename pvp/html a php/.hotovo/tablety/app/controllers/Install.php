<?php

namespace controllers;

use models\Index;

class Install
{
    public function instalace_pujcovna() {
        \models\Pujcovna::setdown(); // drop table pokud existuje
        \models\Pujcovna::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function vsechno() {
        \models\Pujcovna::setdown(); // drop table pokud existuje
        \models\Pujcovna::setup(); // vytvoření tabulky

        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }
} 