<?php

namespace models;

class Pobocka extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'pobocka';

    protected $fieldConf = [
        'nazev' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'adresa' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => false
        ],
        'obchod_id' => [            // foreign key na tabulku obchod
            'type' => 'INT1',
            'nullable' => false,
            'index' => true
        ]
    ];

    protected $relConf = [
        'obchod' => [
            'belongs-to' => \models\Obchod::class
        ]
    ];
}