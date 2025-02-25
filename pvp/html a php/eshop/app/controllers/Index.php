<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        // Zobrazení úvodní stránky s nejnovějšími produkty
        $products = new \models\Product();
        $products = $products->find([], ['limit' => 6, 'order' => 'created_at DESC']);
        $base->set('products', $products);

        $base->set('content', 'default.html');
        echo \Template::instance()->render('index.html');
    }

    public function getAdminPanel(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zobrazení admin panelu
        $base->set('content', 'admin/panel.html');
        echo \Template::instance()->render('index.html');
    }

    public function postAdminPanel(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zpracování dat z admin panelu (zatím nic neděláme)
        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Nastavení bylo uloženo.']);
        $base->reroute('/admin');
    }

    public function getVytvoritObchod(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zobrazení formuláře pro vytvoření obchodu
        $base->set('content', 'admin/vytvorit_obchod.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritObchod(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zpracování dat z formuláře pro vytvoření obchodu
        $name = $base->get('POST.name');
        $description = $base->get('POST.description'); // Předpokládám, že máš pole description ve formuláři

        // Vytvoření instance modelu Obchod
        $obchod = new \models\Obchod();
        $obchod->name = $name;
        $obchod->description = $description;

        // Uložení do databáze
        if ($obchod->validate() && $obchod->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Obchod byl úspěšně vytvořen.']);
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při vytváření obchodu.']);
        }

        $base->reroute('/admin');
    }

    public function getVytvoritPobocku(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zobrazení formuláře pro vytvoření pobočky
        $base->set('content', 'admin/vytvorit_pobocku.html');
        echo \Template::instance()->render('index.html');
    }

    public function postVytvoritPobocku(\Base $base)
    {
        // Kontrola přihlášení a role pro přístup do administrace
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Pro přístup do administrace se musíte přihlásit jako administrátor.']);
            $base->reroute('/login');
            return;
        }

        // Zpracování dat z formuláře pro vytvoření pobočky
        $name = $base->get('POST.name');
        $address = $base->get('POST.address'); // Předpokládám, že máš pole address ve formuláři

        // Vytvoření instance modelu Pobocka
        $pobocka = new \models\Pobocka();
        $pobocka->name = $name;
        $pobocka->address = $address;

        // Uložení do databáze
        if ($pobocka->validate() && $pobocka->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Pobočka byla úspěšně vytvořena.']);
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při vytváření pobočky.']);
        }

        $base->reroute('/admin');
    }
}