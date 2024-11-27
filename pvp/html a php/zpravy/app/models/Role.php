<?php

namespace models;

class Role extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'role';

    protected $fieldConf = [
        'nazev' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false,
            'index' => true
        ],
        'popis' => [
            'type' => 'TEXT',
            'required' => true
        ],
        'uzivatele' => [
            'has-many' => ['models\Uzivatel', 'role']
        ],
    ];
}