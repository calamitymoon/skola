<?php

namespace models;

class Uzivatel extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'uzivatel';

    protected $fieldConf = [
        'avatar' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => true
        ],
        'nick' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false,
            'index' => true
        ],
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'prijmeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'email' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true,
            'nullable' => false,
        ],
        'heslo' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => false,
        ],
        'zpravy' => [
            'has-many' => ['models\Zpravy', 'id_from'],
        ]
    ];
}