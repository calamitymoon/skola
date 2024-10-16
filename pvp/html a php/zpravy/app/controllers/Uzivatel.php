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
}