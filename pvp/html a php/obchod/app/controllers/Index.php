<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }

    public function getVytvoritObchod(\Base $base)
    {
        $base->set('title', 'Vytvořit obchod');
        $base->set('content', '/admin/vytvorit_obchod.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritObchod(\Base $base)
    {
        $obchod = new \models\Obchod();
        $obchod->copyfrom($base->get('POST'));
        $obchod->save();
        $base->reroute('/admin');
    }

    public function getVytvoritPobocku(\Base $base)
    {
        $base->set('title', 'Vytvořit pobočku');
        $base->set('content', '/admin/vytvorit_pobocku.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritPobocku(\Base $base)
    {
        $pobocka = new \models\Pobocka();
        $pobocka->copyfrom($base->get('POST'));
        $pobocka->save();
        $base->reroute('/admin');
    }

    public function getAdminPanel(\Base $base)
    {
        $base->set('title', 'Admin panel');
        $base->set('content', '/admin/panel.html');

        
        // $typy = new \models\Typ();
        // $typy = $typy->find();
        // $results = [];
        // foreach ($typy as $typ) {
        //     $results[] = $typ->cast();
        // }
        // $base->set('typy', json_encode($results));
        $typ = new \models\Typ();
        $typyList = $typ->find();

        $nazvy = [];
        $ids = [];

        foreach ($typyList as $t) {
            $nazvy[] = $t->typy;
            $ids[] = $t->id;
        }

        $typyResults = [];
        foreach ($typyList as $typ) {
            $typyResults[] = $typ->cast();
        }
        $base->set('typy', json_encode($typyResults));
        $base->set('typy_nazvy', json_encode($nazvy));
        $base->set('typy_ids', json_encode($ids));


        // $pobocka = new \models\Pobocka();
        // $pobockyList = $pobocka->find();
        // $results = [];
        // foreach ($pobockyList as $pob) {
        //     $results[] = $pob->cast();
        // }
        // $base->set('pobocka', json_encode($results));
        $pobocka = new \models\Pobocka();
        $pobockyList = $pobocka->find();

        $nazvy = [];
        $adresy = [];

        foreach ($pobockyList as $pob) {
            $nazvy[] = $pob->nazev;
            $adresy[] = $pob->adresa;
        }

        $pobockaResults = [];
        foreach ($pobockyList as $pob) {
            $pobockaResults[] = $pob->cast();
        }
        $base->set('pobocka', json_encode($pobockaResults));
        $base->set('pobocka_nazvy', json_encode($nazvy));
        $base->set('pobocka_adresy', json_encode($adresy));


        // $obchod = new \models\Obchod();
        // $obchodyList = $obchod->find();
        // $results = [];
        // foreach ($obchodyList as $ob) {
        //     $results[] = $ob->cast();
        // }
        // $base->set('obchod', json_encode($results));
        $obchod = new \models\Obchod();
        $obchodyList = $obchod->find();

        $typy = [];
        $kategorie = [];

        foreach ($obchodyList as $ob) {
            $typy[] = $ob->typ;
            $kategorie[] = $ob->kategorie;
        }

        $obchodResults = [];
        foreach ($obchodyList as $ob) {
            $obchodResults[] = $ob->cast();
        }
        $base->set('obchod', json_encode($obchodResults));
        $base->set('obchod_typy', json_encode($typy));
        $base->set('obchod_kategorie', json_encode($kategorie));


        // $kategorie = new \models\Kategorie();
        // $kategorieList = $kategorie->find();
        // $results = [];
        // foreach ($kategorieList as $kat) {
        //     $results[] = $kat->cast();
        // }
        // $base->set('kategorie', json_encode($results));
        $kategorie = new \models\Kategorie();
        $kategorieList = $kategorie->find();

        $nazvy = [];
        $ids = [];

        foreach ($kategorieList as $kat) {
        $nazvy[] = $kat->vsechny;
        $ids[] = $kat->_id;
        }

        $kategorieResults = [];
        foreach ($kategorieList as $kat) {
            $kategorieResults[] = $kat->cast();
        }
        $base->set('kategorie', json_encode($kategorieResults));
        $base->set('kategorie_nazvy', json_encode($nazvy));
        $base->set('kategorie_ids', json_encode($ids));

// --------------------------------------------------------------------------------------------------------------------------------------------

        $obchod = new \models\Obchod();
        $pobocka = new \models\Pobocka();
        $typ = new \models\Typ();

        $obchodyList = $obchod->find();
        $obchodL = [];
        foreach ($obchodyList as $obchod) {
            $obchodL[] = $obchod->cast();
        }
        $base->set('obchodL', $obchodL);

        $pobockyList = $pobocka->find();
        $pobockaL = [];
        foreach ($pobockyList as $pobocka) {
            $pobockaL[] = $pobocka->cast();
        }
        $base->set('pobockaL', $pobockaL);

        $typyList = $typ->find();
        $typyL = [];
        foreach ($typyList as $typ) {
            $typyL[] = $typ->cast();
        }
        $base->set('typyL', $typyL);
        
        echo \Template::instance()->render('index.html');
    }

    public function postAdminPanel (\Base $base)
    {
        foreach ($f3->POST as $key => $value) {
            if (strpos($key, 'typ_') === 0) {
                $obchodId = substr($key, 4);
                $obchod = new \models\Obchod();
                $obchod->load(['id=?', $obchodId]);
                $obchod->typ = $value;
                $obchod->save();
            }
            
            if (strpos($key, 'pobocky_') === 0) {
                $obchodId = substr($key, 8, -2);
                $obchod = new \models\Obchod();
                $obchod->load(['id=?', $obchodId]);
                $obchod->pobocky = $value;
                $obchod->save();
            }
        }

        $f3->reroute('/admin');
    }
}