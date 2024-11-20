<?php

namespace models;

class Login extends \DB\Cortex
{
    protected $db = 'DB',
            $table = 'prihlaseni';

    protected $fieldConf = [
        'state' => [
            'type' => 'BOOLEAN',
            'default' => 0,
        ],
        'last_login' => [
            'type' => 'TIMESTAMP',
            'default' => \DB\SQL\Schema::DF_CURRENT_TIMESTAMP,
        ],
        'uzivatel' => [
            'belongs-to-one' => 'models\Uzivatel'
        ]
    ];
}