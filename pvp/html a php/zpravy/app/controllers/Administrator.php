<?php

namespace controllers;

class Administrator extends AbstractController
{
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