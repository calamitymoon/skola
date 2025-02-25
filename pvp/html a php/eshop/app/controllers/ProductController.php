<?php

namespace controllers;

class ProductController
{
    public function create(\Base $base)
    {
        // Kontrola přihlášení
        if (!$base->exists('SESSION.user_id')) {
            $base->reroute('/login');
            return;
        }

        // Kontrola role (pouze admin má přístup)
        if ($base->get('SESSION.role') !== 'admin') {
            $base->reroute('/');
            return;
        }
        
        $product = new \models\Product();
        $product->name = $base->get('POST.name');
        $product->price = $base->get('POST.price');
        $product->stock = $base->get('POST.stock');

        if ($product->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Produkt byl úspěšně vytvořen.']);
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při vytváření produktu.']);
        }

        $base->reroute('/admin/produkty');
    }

    public function edit(\Base $base, $params)
    {
        // Kontrola přihlášení
        if (!$base->exists('SESSION.user_id')) {
            $base->reroute('/login');
            return;
        }

        // Kontrola role (pouze admin má přístup)
        if ($base->get('SESSION.role') !== 'admin') {
            $base->reroute('/');
            return;
        }
        
        $product = new \models\Product();
        $product->load(['id = ?', $params['id']]);

        if ($product->dry()) {
            $base->error(404, 'Produkt nebyl nalezen.');
        }

        if ($base->exists('POST.name')) {
            $product->name = $base->get('POST.name');
            $product->price = $base->get('POST.price');
            $product->stock = $base->get('POST.stock');

            if ($product->validate() && $product->save()) {
                $base->set('SESSION.message', ['type' => 'success', 'text' => 'Produkt byl úspěšně upraven.']);
            } else {
                $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při úpravě produktu.']);
            }

            $base->reroute('/admin/produkty');
        }

        $base->set('product', $product);
        $base->set('content', 'product/edit.html');
        echo \Template::instance()->render('index.html');
    }

    public function list(\Base $base)
    {
        // Kontrola přihlášení
        if (!$base->exists('SESSION.user_id')) {
            $base->reroute('/login');
            return;
        }

        // Kontrola role (pouze admin má přístup)
        if ($base->get('SESSION.role') !== 'admin') {
            $base->reroute('/');
            return;
        }
        
        $products = new \models\Product();
        $base->set('products', $products->find());
        $base->set('content', 'product/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function createForm(\Base $base)
    {
        // Kontrola přihlášení a role (pouze admin)
        if (!$base->exists('SESSION.user_id') || $base->get('SESSION.role') !== 'admin') {
            $base->reroute('/login');
            return;
        }

        $base->set('content', 'product/create.html');
        echo \Template::instance()->render('index.html');
    }
}