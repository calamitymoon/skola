<?php

namespace controllers;

class AbstractController
{
    public function beforeRoute(\Base $base)
    {
        if (!$base->get('SESSION.uid')) {
            $base->reroute('/user/login');
        }
    }
}