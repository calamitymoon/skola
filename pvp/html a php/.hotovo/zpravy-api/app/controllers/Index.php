<?php

namespace controllers;

class Index
{
    public function index(\Base $base)
    {
        $base->set('title', 'Rest API');
        $base->reroute('https://amfex.xyz/unauthorized/');
    }
}