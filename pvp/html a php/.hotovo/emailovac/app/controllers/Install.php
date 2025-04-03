<?php

namespace controllers;

use models\Index;

class Install
{
    public function setup(\Base $base)
    {
        // \models\Uzivatel::setdown();
        // \models\Uzivatel::setup();
        // \models\NoveHeslo::setdown();
        // \models\NoveHeslo::setup();
        \models\EmailStatus::setdown();
        \models\EmailStatus::setup();
        
        \Flash::instance()->addMessage('Instalace dokončena.', 'success');
        $base->reroute('/');
    }
}