<?php

namespace controllers;

class Uzivatel
{
    public function getRegistrace(\Base $base)
    {
        $base->set('title', 'Registrace');
        $base->set('content', '/uzivatel/registrace.html');
        echo \Template::instance()->render('index.html');
    }

    public function postRegistrace(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $existujiciEmail = $uzivatel->findone(['email=?', $base->get('POST.email')]);
        $existujiciNick = $uzivatel->findone(['nick=?', $base->get('POST.nick')]);

        if ($existujiciEmail) {
            echo "<script>
                    alert('Zadaný email je již zaregistrován.');
                    window.location.href = '/zpravy/user/add';
                </script>";
        } elseif ($existujiciNick) {
            echo "<script>
                    alert('Zadaný nick je již zaregistrován.');
                    window.location.href = '/zpravy/user/add';
                </script>";
        } else {
            $uzivatel->copyfrom($base->get('POST'));
            $uzivatel->save();
            $base->reroute('/user/login');
        }
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
        if ($uz && $uz->heslo === $base->get('POST.heslo')) {
            $base->set('SESSION.jmeno', $uz->jmeno);
            $base->set('SESSION.uid', $uz->id);
            $base->set('SESSION.nick', $uz->nick);
            $base->reroute('/message/list');
        } else {
            $base->reroute('/user/login');
        }
    }

    public function getList(\Base $base)
    {
        $base->set('title', 'Seznam uzivatelu');
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('users', $users->find());
        $base->set('content', '/uzivatel/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION.id');
        $base->clear('SESSION.jmeno');
        $base->clear('SESSION.uid');
        $base->reroute('/');
    }
    
    public function getUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $base->get('PARAMS.id')]);
        
        if ($uz) {
            $base->set('uzivatel', $uz);
            $base->set('title', 'Upravit uzivatele');
            $base->set('content', '/uzivatel/upravit.html');
            echo \Template::instance()->render('index.html');
        } else {
            $base->reroute('/');
        }
    }

    public function postUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel->load($base->get('PARAMS.id'));
        $uzivatel->copyFrom('POST');
        $uzivatel->save();
        $base->reroute('/user/list');
        if ($uz->load(['id = ?', $id])) {
            $uz->id = $_POST['id'];
            $uz->prezdivka = $_POST['prezdivka'];
            $uz->jmeno = $_POST['jmeno'];
            $uz->prijmeni = $_POST['prijmeni'];
            $uz->email = $_POST['email'];
            $uz->heslo = $_POST['heslo'];
            
            $mapper->save();
        } else {
            echo "uzivatel neexistuje";
        }
    }
}