<?php

namespace models;

class EmailStatus extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'email_status';

    protected $fieldConf = [
        'id_uzivatele' => [
            'type' => 'INT',
            'required' => true,
            'nullable' => false,
            'belongs-to-one' => '\models\Uzivatel'
        ],
        'hash' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true,
            'nullable' => false
        ],
        'email' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'odeslano' => [
            'type' => 'DATETIME',
            'required' => false,
            'nullable' => true
        ],
        'zobrazeno' => [
            'type' => 'DATETIME',
            'required' => false,
            'nullable' => true
        ],
        'resetovano' => [
            'type' => 'DATETIME',
            'required' => false,
            'nullable' => true
        ],
        'expirovano' => [
            'type' => 'DATETIME',
            'required' => false,
            'nullable' => true
        ],
        'platnost' => [
            'type' => 'DATETIME',
            'required' => false,
            'nullable' => true
        ]
    ];
}