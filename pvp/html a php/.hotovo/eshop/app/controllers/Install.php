<?php

namespace controllers;

class Install
{
    public function setup_uzivatel(\Base $base)
    {
        \models\User::setdown(); // Drop table pokud existuje
        \models\User::setup(); // Vytvoření tabulky

        // Vytvoření admin uživatele (příklad)
        // $user = new \models\User();
        // $user->username = 'admin';
        // $user->set_password('password'); // Změň na silnější heslo!
        // $user->role = 'admin';
        // $user->save();

        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Tabulka uživatelů byla vytvořena.']);
    }

    public function instalace_obchod(\Base $base)
    {
        \models\Obchod::setdown(); // Drop table pokud existuje
        \models\Obchod::setup(); // Vytvoření tabulky
        
        $obchod = new \models\Obchod();
        $obchod->name = 'CZC';
        $obchod->description = 'Největší počítačový obchod v ČR';
        $obchod->save();
        
        $obchod = new \models\Obchod();
        $obchod->name = 'Alza';
        $obchod->description = 'Největší obchod s elektronikou v ČR';
        $obchod->save();

        $obchod = new \models\Obchod();
        $obchod->name = 'Mall';
        $obchod->description = 'Obchod s elektronikou a spotřebním zbožím';
        $obchod->save();

        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Tabulka uživatelů byla vytvořena a admin uživatel byl přidán.']);
    }

    public function instalace_customer(\Base $base)
    {
        \models\Customer::setdown(); // Drop table pokud existuje
        \models\Customer::setup(); // Vytvoření tabulky

        $customer = new \models\Customer();
        $customer->name = 'tohohle neznam';
        $customer->email = 'juzadominik@seznam.cz';
        $customer->save();
    }

    public function instalace_order(\Base $base)
    {
        \models\Order::setdown(); // Drop table pokud existuje
        \models\Order::setup(); // Vytvoření tabulky

        $order = new \models\Order();
        $order->customer_id = 1;
        $order->total_price = 23990;
        $order->save();
    }

    public function instalace_typ(\Base $base)
    {
        \models\Type::setdown(); // Drop table pokud existuje
        \models\Type::setup(); // Vytvoření tabulky

        $obchod = new \models\Type();
        $obchod->typ = 'Mobil';
        $obchod->save();
        
        $obchod = new \models\Type();
        $obchod->typ = 'Notebook';
        $obchod->save();
        
        $obchod = new \models\Type();
        $obchod->typ = 'Tablet';
        $obchod->save();

        $obchod = new \models\Type();
        $obchod->typ = 'Počítač';
        $obchod->save();
        
        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Tabulka typů byla vytvořena a typy byly přidány.']);
    }

    public function instalace_products(\Base $base)
    {
        \models\Product::setdown(); // Drop table pokud existuje
        \models\Product::setup(); // Vytvoření tabulky

        $product = new \models\Product();
        $product->name = 'iPhone 12';
        $product->price = 23990;
        $product->stock = 10;
        $product->type_id = 1;
        $product->save();

        $product = new \models\Product();
        $product->name = 'Samsung Galaxy S21';
        $product->price = 19990;
        $product->stock = 5;
        $product->type_id = 1;
        $product->save();

        $product = new \models\Product();
        $product->name = 'MacBook Pro 13"';
        $product->price = 39990;
        $product->stock = 3;
        $product->type_id = 2;
        $product->save();

        $product = new \models\Product();
        $product->name = 'iPad Pro 12.9"';
        $product->price = 23990;
        $product->stock = 7;
        $product->type_id = 3;
        $product->save();

        $product = new \models\Product();
        $product->name = 'iMac 27"';
        $product->price = 49990;
        $product->stock = 2;
        $product->type_id = 4;
        $product->save();

        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Tabulka produktů byla vytvořena a produkty byly přidány.']);
    }

    public function vsechno(\Base $base)
    {
        $this->setup_uzivatel($base);
        $this->instalace_obchod($base);
        $this->instalace_typ($base);
        $this->instalace_products($base);
        $this->instalace_order($base);
        $this->instalace_customer($base);

        $base->set('SESSION.message', ['type' => 'success', 'text' => 'Všechno bylo úspěšně nainstalováno!']);
        $base->reroute('/');
    }
}