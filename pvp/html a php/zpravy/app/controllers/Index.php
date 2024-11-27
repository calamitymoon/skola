<?php

namespace controllers;

class Index extends AbstractController
{
    public function index(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }

    public function getRegistrace(\Base $base)
    {
        $base->set('title', 'Registrace');
        $base->set('content', '/uzivatel/registrace.html');
        echo \Template::instance()->render('index.html');
    }

    public function postRegistrace(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel->copyfrom($base->get('POST'));
        $uzivatel->save();
        $base->reroute('/');
    }

    public function getLogin(\Base $base)
    {
        $base->set('title', 'Přihlášení');
        $base->set('content', '/uzivatel/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function postLogin(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['email=?', $base->get('POST.email')]);
        if($uz === false){
            \Flash::instance()->addMessage('Uživatel neexistuje, nebo je zablokován. Kontaktujte administrátora.', 'danger');
            $base->reroute('/user/login');
        }
        $login = new \models\Login();
        $login->uzivatel = $uz;
        if(!password_verify($base->get('POST.heslo'), $uz->heslo)){
            \Flash::instance()->addMessage('Špatné uživatelské jméno nebo heslo.', 'danger');
            $login->save(); //neuspesny pokus o prihlaseni je default.
            $nalezeno = $login->afind(['uzivatel = ?',$uz->id], ['order'=>'id DESC', 'limit'=>3]);
            $pocetDobre = count(array_filter($nalezeno, function($l){return $l['state'] == 1;}));
            if($pocetDobre == 0){
                $uz->is_locked = 1;
                $uz->save();
                \Flash::instance()->clearMessages();
                \Flash::instance()->addMessage('Uživatel je blokován, kontaktujte administrátora.', 'danger');
            }
            $base->reroute('/user/login');
        }
        $login->state = 1;
        $login->save();
        if($uz->is_locked){
            \Flash::instance()->addMessage('Uživatel je blokován, kontaktujte administrátora.', 'danger');
            $base->reroute('/user/login');
        }
        $base->set('SESSION.uid', $uz->id);
        $base->set('SESSION.nick', $uz->nick);
        $base->set('SESSION.jmeno', $uz->jmeno);
        $base->set('SESSION.prijmeni', $uz->prijmeni);
        $base->set('SESSION.email', $uz->email);
        $base->set('SESSION.avatar', '/zpravy/assets/avatars/'.$uz->nick.'.png');
        $base->set('SESSION.role', $uz->role->nazev);
        
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $uz->id]);
        $uz->avatar = '/zpravy/assets/avatars/'.$uz->nick.'.png';
        $uzivatel->save();
        
        $base->reroute('/');
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION');
        $base->reroute('/');
    }
}