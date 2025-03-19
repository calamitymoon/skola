<?php

namespace models;

class Ankety extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'ankety';

    protected $fieldConf = [
        'otazka' => [
            'type' => 'VARCHAR128',
        ],
        'moznosti' => [
            'type' => 'VARCHAR256',
        ],
        'odesilatel' => [
            'type' => 'VARCHAR128',
        ],
        'id_ankety' => [
            'type' => 'VARCHAR128',
        ]
    ];
}