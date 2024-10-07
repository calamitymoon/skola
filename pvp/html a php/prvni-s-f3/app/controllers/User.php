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

    public function getOdhlasit(\Base $base)
    {
        $base->clear('SESSION.id');
        $base->reroute('/pokus');
    }

    public function getSmazat(\Base $base)
    {
        $id = $base->get('GET.id');
        $user = new \models\User();
        $user->load($id);
        $user->delete();
        $base->reroute('/pokus');
    }

    public function postUpravit(\Base $base)
    {
        $uzivatel = new \models\User();
        $uz = $uzivatel->findone($base->get('PARAMS.id'));
        $uz->copyFrom('POST');
        $uz->save();
        $base->reroute('/user/list');
    }

    public function getUpravit(\Base $base)
    {
        $user = new \models\User();
        $uz = $user->findone($base->get('PARAMS.id'));
        $base->set('user', $uz);
        $base->set('title', 'Upravit uzivatele');
        $base->set('content', '/user/upravit.html');
        echo \Template::instance()->render('index.html');
    }

}