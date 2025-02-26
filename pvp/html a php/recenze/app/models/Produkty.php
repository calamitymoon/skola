<?php

namespace models;

class Produkty extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'produkty';

    protected $fieldConf = [
        'nazev' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false
        ],
        'cena' => [
            'type' => 'INT2',
            'required' => true,
            'nullable' => false
        ],
        'popis' => [
            'type' => 'TEXT',
            'required' => true,
            'unique' => true,
            'nullable' => false
        ]
    ];
}