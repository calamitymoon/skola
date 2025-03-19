<?php

namespace models;

class Zpravy extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'zpravy';

    protected $fieldConf = [
        'id_from' => [
            'belongs-to-one' => 'models\Uzivatel',
        ],
        'id_to' => [
            'belongs-to-one' => 'models\Uzivatel',
        ],
        'text' => [
            'type' => 'TEXT',
            'required' => true,
            'nullable' => false
        ],
        'precteno' => [
            'type' => 'BOOLEAN',
            'default' => false
        ]
    ];
}