<?php

namespace controllers;

class Administrator extends AbstractController
{
    public function getPanel(\Base $base)
    {
        $base->set('title', 'Admin panel');
        $role = new \models\Role(); // vyrobit model uzivatelu
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('role', $role->find());
        $base->set('users', $users->find());
        $base->set('content', '/administrator/panel.html');
        echo \Template::instance()->render('index.html');
    }
}