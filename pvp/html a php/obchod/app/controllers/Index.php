<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }

    public function getVytvoritObchod(\Base $base)
    {
        $base->set('title', 'Vytvořit obchod');
        $base->set('content', '/admin/vytvorit_obchod.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritObchod(\Base $base)
    {
        $obchod = new \models\Obchod();
        $obchod->copyfrom($base->get('POST'));
        $obchod->save();
        $base->reroute('/admin');
    }

    public function getVytvoritPobocku(\Base $base)
    {
        $base->set('title', 'Vytvořit pobočku');
        $base->set('content', '/admin/vytvorit_pobocku.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritPobocku(\Base $base)
    {
        $pobocka = new \models\Pobocka();
        $pobocka->copyfrom($base->get('POST'));
        $pobocka->save();
        $base->reroute('/admin');
    }

    public function getAdminPanel(\Base $base)
    {
        $base->set('title', 'Admin panel');
        $base->set('content', '/admin/panel.html');

        $typy = new \models\Typ();
        $typy = json_encode($typy->find());
        $base->set('typy', $typy);

        $pobocka = new \models\Pobocka();
        $pobocka = json_encode($pobocka->find());
        $base->set('pobocka', $pobocka);

        $obchod = new \models\Obchod();
        $obchod = json_encode($obchod->find());
        $base->set('obchod', $obchod);

        $kategorie = new \models\Kategorie();
        $kategorie = json_encode($kategorie->find());
        $base->set('kategorie', $kategorie);

        echo \Template::instance()->render('index.html');
    }
}