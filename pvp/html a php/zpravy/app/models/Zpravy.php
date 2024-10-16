<?php

namespace models;

class Zpravy extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'zpravy';

    protected $fieldConf = [
        'text' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false,
            'index' => true
        ],
        'id_from' => [
            'belongs-to-one' => 'models\Uzivatel',
        ],
        'id_to' => [
            'belongs-to-one' => 'models\Uzivatel',
        ],
        'precteno' => [
            'type' => 'BOOLEAN',
            'default' => false
        ]
    ];
}