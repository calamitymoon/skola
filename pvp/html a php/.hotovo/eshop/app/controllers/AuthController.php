<?php

namespace controllers;

class AuthController
{
    public function loginForm(\Base $base)
    {
        $base->set('content', 'auth/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function login(\Base $base)
    {
        $username = $base->get('POST.username');
        $password = $base->get('POST.password');

        $user = new \models\User();
        $user->load(['username = ?', $username]);

        if ($user->dry()) {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Špatné uživatelské jméno nebo heslo.']);
            $base->reroute('/login');
            return;
        }

        if ($user->password !== $password) {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Špatné uživatelské jméno nebo heslo.']);
            $base->reroute('/login');
            return;
        }

        // Uložení informací o uživateli do session
        $base->set('SESSION.user_id', $user->id);
        $base->set('SESSION.username', $user->username);
        $base->set('SESSION.role', $user->role);

        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Úspěšně přihlášen.']);
        $base->reroute('/admin/produkty');
    }

    public function logout(\Base $base)
    {
        // Zrušení session
        $base->clear('SESSION');
        $base->reroute('/');
    }

    public function registerForm(\Base $base)
    {
        $base->set('content', 'auth/register.html');
        echo \Template::instance()->render('index.html');
    }

    public function register(\Base $base)
    {
        $username = $base->get('POST.username');
        $password = $base->get('POST.password');

        $user = new \models\User();
        $user->username = $username;
        $user->password = $password;

        if ($user->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Úspěšně registrován.']);
            $base->reroute('/login');
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při registraci.']);
            $base->reroute('/register');
        }
    }
}