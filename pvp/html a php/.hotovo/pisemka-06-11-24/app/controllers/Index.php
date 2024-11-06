<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        $base->set('title', 'Závodíme s vodíkovým autem');
        $base->set('content', '/static/stranka.html');

        $stranka = new \models\Stranka(); // vyrobit model uzivatelu
        $base->set('stranka', $stranka->find());

        echo \Template::instance()->render('index.html');
    }
}