<?php

namespace controllers;

class Administrator extends AbstractController
{
    public function getSpravaAnket(\Base $base)
    {
        $base->set('title', 'Anketa');
        $base->set('content', '/administrator/anketa.html');
        echo \Template::instance()->render('index.html');
    }

    public function postSpravaAnket(\Base $base)
    {
        $ankety = new \models\Ankety();
        $ankety->otazka = $base->get('POST.anketaOtazka');
        $ankety->moznosti = json_encode($base->get('POST.moznost'));
        $ankety->odesilatel = $base->get('SESSION.uid');
        $ankety->id_ankety = $base->get('POST.idankety');
        $ankety->save();
        $base->reroute('/');
    }

    public function getSpravaRoli(\Base $base)
    {
        $base->set('title', 'Admin panel');
        $role = new \models\Role(); // vyrobit model uzivatelu
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('role', $role->find());
        $base->set('users', $users->find());
        $base->set('content', '/administrator/spravaroli.html');
        echo \Template::instance()->render('index.html');
    }
    
    public function getSpravaUzivatelu(\Base $base)
    {
        $base->set('title', 'Admin panel');
        $role = new \models\Role(); // vyrobit model uzivatelu
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('role', $role->find());
        $base->set('users', $users->find());
        $base->set('content', '/administrator/spravauzivatelu.html');
        echo \Template::instance()->render('index.html');
    }
}