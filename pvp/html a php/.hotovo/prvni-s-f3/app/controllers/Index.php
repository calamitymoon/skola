<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        echo \Template::instance()->render('index.html');
    }

    public function pokus(\Base $base)
    {
        $base->set('content', 'nastenka.html');
        echo \Template::instance()->render('index.html');
    }
}