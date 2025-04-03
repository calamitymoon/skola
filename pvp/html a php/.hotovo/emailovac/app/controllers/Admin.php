<?php

namespace controllers;

class Admin
{
    public function accessCheck(\Base $base)
    {
        if (!$base->get('SESSION.admin')) {
            \Flash::instance()->addMessage('Přístup odepřen. Tato sekce je pouze pro administrátory.', 'danger');
            $base->reroute('/');
            exit;
        }
    }
    
    public function index(\Base $base)
    {
        $this->accessCheck($base);
    
        $base->clear('CACHE');

        $emailStatus = new \models\EmailStatus();
        $this->checkVyprselyTokeny();
        
        $statusy = $emailStatus->find(null, ['order' => 'odeslano DESC'], null, 0);
        
        $base->set('statusy', $statusy);
        $base->set('title', 'Admin - Přehled resetování hesel');
        $base->set('content', 'static/admin.html');
        echo \Template::instance()->render('index.html');
    }
    
    private function checkVyprselyTokeny()
    {
        $emailStatus = new \models\EmailStatus();
        $now = date('Y-m-d H:i:s');
        
        $expired = $emailStatus->find([
            'platnost < ? AND expirovano = ? AND resetovano = ?', 
            $now, NULL, NULL
        ]);
        
        if ($expired) {
            foreach ($expired as $status) {
                $status->expirovano = $now;
                $status->save();
            }
        }
    }
}