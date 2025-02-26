<?php

namespace models;

class Uzivatele extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'uzivatele';

    protected $fieldConf = [
        'prezdivka' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false
        ],
        'ip' => [
            'type' => 'VARCHAR128',
            'nullable' => false,
            'default' => ''
        ],
    ];
}