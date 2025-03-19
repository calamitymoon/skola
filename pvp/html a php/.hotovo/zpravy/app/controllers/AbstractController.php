<?php

namespace controllers;

class AbstractController
{
    public function beforeRoute(\Base $base)
    {
        if (!$base->get('SESSION.uid')) {
            // $base->reroute('/user/login');
        }
        $this->prava($base->get('SESSION.role'));
    }

    private function prava($uzivatel)
    {
        $access = \Access::instance();
        $access->policy('allow');
        $access->deny('/admin/manage/users');
        $access->deny('/admin/manage/survey');
        $access->allow('/admin/manage/users', 'admin');
        $access->allow('/admin/manage/survey', 'admin');
        // echo "debug | pristup povolen s roli: $uzivatel";
        $access->authorize($uzivatel, function($route,$subject){
            \Flash::instance()->addMessage('Nemáte dostatečná oprávnění.', 'danger');
            \Base::instance()->reroute('/');
        });
    }
}