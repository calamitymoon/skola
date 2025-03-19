<?php

namespace models;

class Obchod extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'obchody';
    protected $fieldConf = [
        'name' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'description' => [
            'type' => 'TEXT'
        ]
    ];
}