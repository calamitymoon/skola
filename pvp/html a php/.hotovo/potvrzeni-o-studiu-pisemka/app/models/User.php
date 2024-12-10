<?php

namespace models;

class User extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'uzivatel';

    protected $fieldConf = [
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'prijmeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'email' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'heslo' => [
            'type'=> 'VARCHAR256',
            'required' => true,
            'nullable' => false
        ],
        'adresa' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'trida' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'datumnarozeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ]
    ];

    public function set_heslo($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }
}