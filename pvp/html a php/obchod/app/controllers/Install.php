<?php

namespace controllers;

use models\Index;

class Install
{
    private function kategorie($pole)
    {
        foreach ($pole as $r) {
            $kategorie = new \models\Kategorie();
            $kategorie->vsechny = $r['vsechny'];
            $kategorie->save();
        }
    }
    private function typ($pole)
    {
        foreach ($pole as $r) {
            $typ = new \models\Typ();
            $typ->typy = $r['typy'];
            $typ->save();
            unset($typ);
        }
    }

    
    public function instalace_kategorie() {
        \models\Kategorie::setdown(); // drop table pokud existuje
        \models\Kategorie::setup(); // vytvoření tabulky

        $kategorie = new \models\Kategorie();
        $this->kategorie([
            ['vsechny' => 'Elektronika'],
            ['vsechny' => 'Oblečení'],
            ['vsechny' => 'Potraviny'],
            ['vsechny' => 'Sport'],
            ['vsechny' => 'Nábytek'],
            ['vsechny' => 'Drogérie'],
            ['vsechny' => 'Hračky'],
            ['vsechny' => 'Zahrada'],
            ['vsechny' => 'Auto-moto'],
            ['vsechny' => 'Stavebniny']
        ]); // vložení dat
        $kategorie->save(); // uložení dat
        
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_obchod() {
        \models\Obchod::setdown(); // drop table pokud existuje
        \models\Obchod::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_pobocka() {
        \models\Pobocka::setdown(); // drop table pokud existuje
        \models\Pobocka::setup(); // vytvoření tabulky
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function instalace_typ() {
        \models\Typ::setdown(); // drop table pokud existuje
        \models\Typ::setup(); // vytvoření tabulky
        
        $typ = new \models\Typ();
        $this->typ([
            array('typy' => 'Fyzický'),
            array('typy' => 'Internetový'),
        ]); // vložení dat
        $typ->save(); // uložení dat
        \Base::instance()->reroute('/'); // přesměrování na hlavní stránku
    }

    public function vsechno() {
        \models\Kategorie::setdown(); // drop table pokud existuje
        \models\Kategorie::setup(); // vytvoření tabulky
        $kategorie = new \models\Kategorie();
        $this->kategorie([
            ['vsechny' => 'Elektronika'],
            ['vsechny' => 'Oblečení'],
            ['vsechny' => 'Potraviny'],
            ['vsechny' => 'Sport'],
            ['vsechny' => 'Nábytek'],
            ['vsechny' => 'Drogérie'],
            ['vsechny' => 'Hračky'],
            ['vsechny' => 'Zahrada'],
            ['vsechny' => 'Auto-moto'],
            ['vsechny' => 'Stavebniny']
        ]); // vložení dat
        $kategorie->save(); // uložení dat

        \models\Obchod::setdown(); // drop table pokud existuje
        \models\Obchod::setup(); // vytvoření tabulky

        \models\Pobocka::setdown(); // drop table pokud existuje
        \models\Pobocka::setup(); // vytvoření tabulky

        \models\Typ::setdown(); // drop table pokud existuje
        \models\Typ::setup(); // vytvoření tabulky
        
        $typ = new \models\Typ();
        $this->typ([
            ['typy' => 'Fyzický'],
            ['typy' => 'Internetový'],
        ]); // vložení dat
        $typ->save(); // uložení dat

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