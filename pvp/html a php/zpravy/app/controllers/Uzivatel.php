<?php

namespace controllers;

class Uzivatel
{
    public function getRegistrace(\Base $base)
    {
        $base->set('title', 'Registrace');
        $base->set('content', '/uzivatel/registrace.html');
        echo \Template::instance()->render('index.html');
    }

    public function postRegistrace(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel->copyfrom($base->get('POST'));
        $uzivatel->save();
        $base->reroute('/');
    }

    public function getList(\Base $base)
    {
        $base->set('title', 'Seznam uzivatelu');
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('users', $users->find());
        $base->set('content', '/uzivatel/list.html');
        echo \Template::instance()->render('index.html');
    }
}