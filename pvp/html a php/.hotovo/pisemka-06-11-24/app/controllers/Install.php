<?php

namespace controllers;

class Install
{
    public function setup_stranka() {
        \models\Stranka::setdown(); // drop table pokud existuje
        \models\Stranka::setup(); // vytvoření tabulky

        $stranka = new \models\Stranka();
        $stranka->obrazek = '/zavodime-s-vodikovym-autem/assets/img/obrazek.jpg';
        $stranka->nadpis = 'Závodíme s vodíkovým autem.';
        $stranka->popis = 'Právě teď v basketbalové hale.';
        $stranka->save();
    }
    
    public function index(\Base $base)
    {
        $f3 = \Base::instance();
        $f3->config('./app/configs/config.ini');
        $f3->config('./app/configs/routes.ini');
        
        $f3->set('DB', new \DB\SQL(
            $f3->get('db.dsn'),
            $f3->get('db.username'),
            $f3->get('db.password')
        ));
        
        $f3->run();
    }
}