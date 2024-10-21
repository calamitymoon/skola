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

    public function getList(\Base $base)
    {
        $base->set('title', 'Zpravy');
        $zprava = new \models\Zpravy();
        $base->set('zpravy', $zprava->find());
        $base->set('content', '/zprava/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function getPrecteno(\Base $base)
    {
        $base->set('title', 'Precteno');
        $zprava = new \models\Zpravy();
        $zprava->load(["id=?",$base->get('PARAMS.id')]);
        $zprava->precteno = true;
        $zprava->save();
        $base->reroute('/message/list');
    }

    public function getLogin(\Base $base)
    {
        $base->set('title', 'Login');
        $base->set('content', '/uzivatel/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function postLogin(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel = $uzivatel->findone(["email=? AND heslo=?", $base->get('POST.email'), $base->get('POST.heslo')]);
        
        if ($uzivatel->id) {
            $base->set('SESSION.id', $uzivatel->id);
            $base->reroute('/');
        } else {
            $base->reroute('/login');
        }
    }

}