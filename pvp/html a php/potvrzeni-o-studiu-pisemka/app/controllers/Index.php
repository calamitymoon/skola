<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }

    public function getPoslat(\Base $base)
    {
        $base->set('title', 'Odesílaní potvrzení do databáze');
        $base->set('content', '/uzivatel/odeslat.html');
        echo \Template::instance()->render('index.html');
    }

    public function postPoslat(\Base $base)
    {
        $potvrzeni = new \models\Potvrzeni();
        $potvrzeni->jmeno = $base->get('SESSION.jmeno');
        $potvrzeni->prijmeni = $base->get('SESSION.prijmeni');
        $potvrzeni->datumnarozeni = $base->get('SESSION.datumnarozeni');
        $potvrzeni->adresa = $base->get('POST.adresa');
        $potvrzeni->skolnirok = $base->get('POST.skolnirok');
        $potvrzeni->trida = $base->get('POST.trida');
        $potvrzeni->formavzdelani = $base->get('POST.formavzdelani');
        $potvrzeni->odbornaskola = $base->get('POST.odbornaskola');
        $potvrzeni->datumodeslani = date('d-m-Y');
        $potvrzeni->save();
        $base->reroute('/');
    }

    public function getGenerovat(\Base $base)
    {
        $base->set('title', 'Generování potvrzení k tisku');
        $base->set('content', '/uzivatel/generovat.html');
        $potvrzeni = new \models\Potvrzeni();
        $potvrzeni->load(["id=?",$base->get('PARAMS.id')]);
        if ($base->get('SESSION.jmeno') == $potvrzeni->jmeno) {
            $base->set('potvrzeni', $potvrzeni);
        }
        echo \Template::instance()->render('index.html');
    }

    public function getPredloha(\Base $base)
    {
        $base->set('title', 'Zobrazení prázdné, nevyplněné potvrzení k tisku');
        $base->set('content', '/uzivatel/predloha.html');
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
        $uzivatel = new \models\User();
        $uzivatel->copyfrom($base->get('POST'));
        $uzivatel->save();
        $base->reroute('/user/login');
    }

    public function getLogin(\Base $base)
    {
        $base->set('title', 'Přihlášení');
        $base->set('content', '/uzivatel/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function postLogin(\Base $base)
    {
        $uzivatel = new \models\User();
        $uz = $uzivatel->findone(['email=?', $base->get('POST.email')]);
        if ($uz && password_verify($base->get('POST.heslo'), $uz->heslo)) {
        $base->set('SESSION.uid', $uz->id);
        $base->set('SESSION.jmeno', $uz->jmeno);
        $base->set('SESSION.prijmeni', $uz->prijmeni);
        $base->set('SESSION.email', $uz->email);
        $base->set('SESSION.adresa', $uz->adresa);
        $base->set('SESSION.trida', $uz->trida);
        $base->set('SESSION.datumnarozeni', $uz->datumnarozeni);
            $base->reroute('/');
        } else {
            $base->reroute('/user/login');
        }
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION');
        $base->reroute('/');
    }
}