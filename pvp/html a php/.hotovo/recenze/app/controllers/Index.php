<?php

namespace controllers;

class Index
{
    public function getRecenze(\Base $base)
    {
        $base->set('title', 'Recenze');
        $base->set('content', '/recenze/recenze.html');

        $recenze = new \models\Recenze();
        $base->set('recenze', $recenze->find());

        $produkty = new \models\Produkty();
        $base->set('produkty', $produkty->find());

        $uzivatele = new \models\Uzivatele();
        $base->set('uzivatele', $uzivatele->find());

        echo \Template::instance()->render('index.html');
    }

    public function getVytvoritProdukt(\Base $base)
    {
        $base->set('title', 'Vytvořit produkt');
        $base->set('content', '/recenze/vytvorit_produkt.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritProdukt(\Base $base)
    {
        $nazev = $base->get('POST.nazev');
        $popis = $base->get('POST.popis');
        $cena = $base->get('POST.cena');

        $produkt = new \models\Produkty();
        $produkt->nazev = $nazev;
        $produkt->popis = $popis;
        $produkt->cena = $cena;
        $produkt->save();

        $base->reroute('/vytvorit-produkt');
        echo \Template::instance()->render('index.html');
    }

    public function getVytvoritRecenzi(\Base $base)
    {
        $base->set('title', 'Vytvořit recenzi');
        $base->set('content', '/recenze/vytvorit_recenzi.html');

        $produkty = new \models\Produkty();
        $base->set('produkty', $produkty->find());

        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritRecenzi(\Base $base)
    {
        $id_uzivatel = $base->get('POST.id_uzivatel');
        $id_produkt = $base->get('POST.produkt');
        $hodnoceni = $base->get('POST.hodnoceni');
        $nadpis = $base->get('POST.nadpis');
        $popis = $base->get('POST.popis');

        $recenze = new \models\Recenze();
        $recenze->id_uzivatel = $id_uzivatel;
        $recenze->id_produkt = $id_produkt;
        $recenze->hvezdicky = $hodnoceni;
        $recenze->nadpis = $nadpis;
        $recenze->popis = $popis;
        $recenze->save();

        $base->reroute('/vytvorit-recenzi');
        echo \Template::instance()->render('index.html');
    }

    public function getVytvoritUzivatele(\Base $base)
    {
        $base->set('title', 'Vytvořit uživatele');
        $base->set('content', '/uzivatele/vytvorit_uzivatele.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritUzivatele(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }
}