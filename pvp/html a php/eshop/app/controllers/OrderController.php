<?php

namespace controllers;

class OrderController
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
        
        $order = new \models\Order();
        $order->customer_id = $base->get('POST.customer_id');

        // Validace a logika pro přidání produktů do objednávky
        $product_ids = $base->get('POST.product_ids'); // Předpokládáme pole ID produktů
        $quantities = $base->get('POST.quantities'); // Předpokládáme pole množství

        $total_price = 0;

        if (is_array($product_ids) && is_array($quantities) && count($product_ids) === count($quantities)) {
            for ($i = 0; $i < count($product_ids); $i++) {
                $product_id = $product_ids[$i];
                $quantity = $quantities[$i];

                $product = new \models\Product();
                $product->load(['id = ?', $product_id]);

                if ($product->dry()) {
                    $base->set('SESSION.message', ['type' => 'error', 'text' => 'Produkt s ID ' . $product_id . ' nebyl nalezen.']);
                    $base->reroute('/admin/objednavky/vytvorit');
                    return;
                }

                if ($product->stock < $quantity) {
                    $base->set('SESSION.message', ['type' => 'error', 'text' => 'Nedostatečné množství produktu ' . $product->name . ' na skladě.']);
                    $base->reroute('/admin/objednavky/vytvorit');
                    return;
                }

                if ($quantity <= 0) {
                    $base->set('SESSION.message', ['type' => 'error', 'text' => 'Množství produktu ' . $product->name . ' musí být kladné.']);
                    $base->reroute('/admin/objednavky/vytvorit');
                    return;
                }

                $order_item = new \models\OrderItem();
                $order_item->order_id = $order->id;
                $order_item->product_id = $product_id;
                $order_item->quantity = $quantity;
                $order_item->unit_price = $product->price;
                $order_item->save();

                $total_price += $product->price * $quantity;

                // Aktualizace skladových zásob (můžeš přidat logování)
                $product->stock =- $quantity;
                $product->save();
            }
        }

        $order->total_price = $total_price;

        if ($order->validate() && $order->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Objednávka byla úspěšně vytvořena.']);
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při vytváření objednávky.']);
        }

        $base->reroute('/admin/objednavky');
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
        
        $orders = new \models\Order();
        $base->set('orders', $orders->find());
        $base->set('content', 'order/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function detail(\Base $base, $params)
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
        
        $order = new \models\Order();
        $order->load(['id = ?', $params['id']]);

        if ($order->dry()) {
            $base->error(404, 'Objednávka nebyla nalezena.');
        }

        $base->set('order', $order);
        $base->set('content', 'order/detail.html');
        echo \Template::instance()->render('index.html');
    }
}