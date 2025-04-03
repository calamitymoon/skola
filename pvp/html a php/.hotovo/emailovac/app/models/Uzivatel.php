<?php

namespace models;

class Uzivatel extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'uzivatele';

    protected $fieldConf = [
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => true
        ],
        'email' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => true
        ],
        'heslo' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => false,
            'nullable' => true
        ],
    ];
    
    public function set_heslo($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }
}