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
        $uzivatel = new \models\Uzivatele();
        $uzivatel->copyfrom($base->get('POST'));
        $uzivatel->save();
        $base->reroute('/prihlasit-uzivatele');
    }

    public function getPrihlasitUzivatele(\Base $base)
    {
        $base->set('title', 'Přihlášení');
        $base->set('content', '/recenze/prihlasit_uzivatele.html');
        echo \Template::instance()->render('index.html');
    }

    public function postPrihlasitUzivatele(\Base $base)
    {
        $uzivatel = new \models\Uzivatele();
        $uz = $uzivatel->findone(['prezdivka=?', $base->get('POST.prezdivka')]);
        if ($uz && password_verify($base->get('POST.heslo'), $uz->heslo)) {
            $base->set('SESSION.uid', $uz->id);
            $base->set('SESSION.prezdivka', $uz->prezdivka);
            if ($uz->id == 1) {
                $base->set('SESSION.admin', true);
            }
            $base->set('SESSION.prihlasen', true);
            $base->reroute('/');
        } else {
            $base->reroute('/prihlasit-uzivatele');
        }
    }

    public function getOdhlasitUzivatele(\Base $base)
    {
        $base->clear('SESSION');
        $base->reroute('/');
    }
}