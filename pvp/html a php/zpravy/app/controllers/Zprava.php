<?php

namespace controllers;

class Zprava extends AbstractController
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
        $zprava->id_from = $base->get('SESSION.uid');
        $zprava->save();
        $base->reroute('/message/list');
    }

    public function getList(\Base $base)
    {
        $base->set('title', 'Zpravy');
        $zprava = new \models\Zpravy();
        $base->set('zpravy', $zprava->find(['id_to=?'],$base->get('SESSION.uid')));
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
}