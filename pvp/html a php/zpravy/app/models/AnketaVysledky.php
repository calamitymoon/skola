<?php

namespace models;

class AnketaVysledky extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'anketavysledky';

    protected $fieldConf = [
        'anketa_id' => [
            'type' => 'VARCHAR256',
        ],
        'moznost' => [
            'type' => 'VARCHAR128',
        ],
        'pocet' => [
            'type' => 'VARCHAR128',
        ],
        'odesilatel' => [
            'type' => 'VARCHAR128',
        ]
    ];
}