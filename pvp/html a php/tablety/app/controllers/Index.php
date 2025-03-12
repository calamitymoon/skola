<?php

namespace controllers;

class Index
{
    public function getVypujcit(\Base $base)
    {
        $base->set('title', 'Půjčka tabletu');
        $base->set('content', '/pujcka/vypujcit.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVypujcit(\Base $base)
    {
        $jmeno = $base->get('POST.jmeno');
        $tridy = json_encode($base->get('POST.tridy'));
        $vypujceni = $base->get('POST.vypujceni');
        $vraceni = $base->get('POST.vraceni');
        $poznamka = $base->get('POST.poznamka');

        $pujcovna = new \models\Pujcovna();
        $pujcovna->jmeno = $jmeno;
        $pujcovna->tridy = $tridy;
        $pujcovna->vypujceni = $vypujceni;
        $pujcovna->vraceni = $vraceni;
        $pujcovna->poznamka = $poznamka;
        $pujcovna->save();

        $base->reroute('/');
    }

    public function getSeznam(\Base $base)
    {
        $base->set('title', 'Seznam rezervací tabletů');
        $base->set('content', '/pujcka/seznam.html');

        $pujcovna = new \models\Pujcovna();
        $base->set('pujcovna', $pujcovna->find());

        echo \Template::instance()->render('index.html');
    }
}