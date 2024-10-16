<?php

namespace controllers;

class Zprava
{
    public function getAdd(\Base $base)
    {
        $base->set('title', 'Nova zprava');
        $base->set('uzivatele', (new \models\Uzivatel())->find());
        $base->set('content', '/zprava/add.html');
        echo \Template::instance()->render('index.html');
    }

    public function postAdd(\Base $base)
    {
        $zprava = new \models\Zpravy();
        $zprava->copyfrom($base->get('POST'));
        // $zprava->id_from = $base->get('SESSION.id');
        $zprava->save();
        $base->reroute('/');
    }
}