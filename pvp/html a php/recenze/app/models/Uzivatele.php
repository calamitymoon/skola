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
        'heslo' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => false,
            'nullable' => false
        ],
    ];
    
    public function set_heslo($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }
}