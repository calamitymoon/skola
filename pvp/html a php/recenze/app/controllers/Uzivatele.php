<?php

namespace controllers;

class Uzivatele
{
    public function getVytvoritUzivatele(\Base $base)
    {
        $base->set('title', 'Vytvořit uživatele');
        $base->set('content', '/recenze/vytvorit_uzivatele.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritUzivatele(\Base $base)
    {
        
    }
}