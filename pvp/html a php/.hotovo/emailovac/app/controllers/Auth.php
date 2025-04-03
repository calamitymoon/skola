<?php

namespace controllers;

class Auth
{
    public function getLogin(\Base $base)
    {
        $base->set('title', 'Přihlášení');
        $base->set('content', 'static/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function postLogin(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['jmeno=?', $base->get('POST.jmeno')]);
        if ($uz && password_verify($base->get('POST.heslo'), $uz->heslo)) {
            $base->set('SESSION.uid', $uz->id);
            $base->set('SESSION.email', $uz->email);
            $base->set('SESSION.jmeno', $uz->jmeno);
            if ($uz->id == 1) {
                $base->set('SESSION.admin', true);
            }
            $base->set('SESSION.prihlasen', true);
            $base->reroute('/');
        } else {
            $base->reroute('/login');
        }
    }

    public function getRegister(\Base $base)
    {
        $base->set('title', 'Registrace');
        $base->set('content', 'static/registrace.html');
        echo \Template::instance()->render('index.html');
    }

    public function postRegister(\Base $base)
    {
        $jmeno = $base->get('POST.jmeno');
        $heslo = $base->get('POST.heslo');
        $email = $base->get('POST.email');
        $heslo_confirm = $base->get('POST.heslo_confirm');

        if (empty($jmeno) || empty($heslo) || empty($heslo_confirm) || empty($email)) {
            $base->reroute('/register');
            \Flash::instance()->addMessage('Jméno, email a heslo jsou povinné.', 'danger');
            return;
        }

        if ($heslo !== $heslo_confirm) {
            $base->reroute('/register');
            \Flash::instance()->addMessage('Hesla se neshodují.', 'danger');
            return;
        }

        $uzivatel = new \models\Uzivatel();
        $postUzivatel = $uzivatel->findone(['jmeno=?', $jmeno]);
        if ($postUzivatel) {
            $base->reroute('/register');
            \Flash::instance()->addMessage('Uživatel s touto přezdívkou již existuje.', 'danger');
            return;
        }
        
        $postEmail = $uzivatel->findone(['email=?', $email]);
        if ($postEmail) {
            $base->reroute('/register');
            \Flash::instance()->addMessage('Uživatel s tímto emailem již existuje.', 'danger');
            return;
        }

        $uzivatel->jmeno = $jmeno;
        $uzivatel->email = $email;
        $uzivatel->heslo = $heslo;
        $uzivatel->save();

        $base->reroute('/login');
        \Flash::instance()->addMessage('Úspěšně zaregistrován.', 'success');  
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION');
        $base->reroute('/');
    }
}