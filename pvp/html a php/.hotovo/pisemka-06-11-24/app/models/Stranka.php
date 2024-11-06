<?php

namespace models;

class Stranka extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'stranka';

    protected $fieldConf = [
        'obrazek' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'nadpis' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'popis' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
    ];
}