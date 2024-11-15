<?php

namespace models;

class Soubor extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'soubor';

    protected $fieldConf = [
        'nazev' => [
            'type' => 'VARCHAR128',
        ],
        'cesta' => [
            'type' => 'VARCHAR256',
        ],
        'odesilatel' => [
            'type' => 'VARCHAR128',
        ]
    ];
}