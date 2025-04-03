<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        $base->set('title', 'Úvodní stránka');
        $base->set('content', 'static/hlavni_stranka.html');
        echo \Template::instance()->render('index.html');
    }
}