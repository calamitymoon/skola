<?php

namespace controllers;

class User
{
    public function getAddUser(\Base $base)
    {
        $base->set('title', 'Add User');
        $base->set('content', '/user/pridat.html');
        echo \Template::instance()->render('index.html');
    }

    public function postAddUser(\Base $base)
    {
        $user = new \models\User();
        $user->copyFrom('POST');
        $user->save();
        $base->reroute('/pokus');
    }

    public function getList(\Base $base)
    {
        $base->set('title', 'Seznam uzivatelu');
        $users = new \models\User(); // vyrobit model uzivatelu
        $base->set('users', $users->find());
        $base->set('content', '/user/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function getLogin(\Base $base)
    {
        $base->set('title', 'Login');
        $base->set('content', '/user/login.html');
        echo \Template::instance()->render('index.html');
    }
    
    public function postLogin(\Base $base)
    {
        $email = $base->get('POST.email');
        $password = $base->get('POST.heslo');
        $user = new \models\User();
        $uz = $user->findone(['email=?', $email]);
        if ($uz && password_verify($password, $uz->heslo)) {
            $base->set('SESSION.jmeno', $uz->jmeno);
            $base->reroute('/pokus');
        } else {
            $base->reroute('/user/login');
        }
    }

}