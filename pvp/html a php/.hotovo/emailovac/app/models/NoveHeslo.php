<?php

namespace models;

class NoveHeslo extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'nove_heslo';

    protected $fieldConf = [
        'id_uzivatele' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => true,
            'belongs-to' => '\models\Uzivatel'
        ],
        'hash' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true,
            'nullable' => true
        ],
        'platnost' => [
            'type' => 'DATETIME',
            'required' => false,
            'unique' => false,
            'nullable' => true,
        ],
    ];
}