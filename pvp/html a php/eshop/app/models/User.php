<?php

namespace models;

class User extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'users';
    protected $password = '';
    protected $fieldConf = [
        'username' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true
        ],
        'password' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'role' => [
            'type' => 'VARCHAR128',
            'default' => 'user'
        ]
    ];

    public function set_heslo($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }
}