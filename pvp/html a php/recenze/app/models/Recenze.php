<?php

namespace models;

class Recenze extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'recenze';

    protected $fieldConf = [
        'nadpis' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => false,
            'nullable' => false
        ],
        'popis' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => false,
            'nullable' => false
        ],
        'hvezdicky' => [
            'type' => 'INT2',
            'required' => true,
            'unique' => false,
            'nullable' => false
        ],
        'id_uzivatel' => [
            'type' => 'INT2',
            'required' => false,
            'unique' => false,
            'nullable' => false
        ],
        'id_produkt' => [
            'type' => 'INT2',
            'required' => false,
            'unique' => false,
            'nullable' => false
        ]
    ];
}