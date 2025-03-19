<?php

namespace controllers;

class CustomerController
{
    public function create(\Base $base)
    {
        $base->clear('SESSION.message');
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

        $customer = new \models\Customer();
        $customer->name = $base->get('POST.name');
        $customer->email = $base->get('POST.email');

        if ($customer->validate() && $customer->save()) {
            $base->set('SESSION.message', ['type' => 'success', 'text' => 'Zákazník byl úspěšně vytvořen.']);
        } else {
            $base->set('SESSION.message', ['type' => 'error', 'text' => 'Chyba při vytváření zákazníka.']);
        }

        $base->reroute('/admin/zakaznici');
    }

    public function list(\Base $base)
    {
        $base->clear('SESSION.message');
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

        $customers = new \models\Customer();
        $base->set('customers', $customers->find());
        $base->set('content', 'customer/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function detail(\Base $base, $params)
    {
        $base->clear('SESSION.message');
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

        $customer = new \models\Customer();
        $customer->load(['id = ?', $params['id']]);

        if ($customer->dry()) {
            $base->error(404, 'Zákazník nebyl nalezen.');
        }

        $base->set('customer', $customer);
        $base->set('content', 'customer/detail.html');
        echo \Template::instance()->render('index.html');
    }
}