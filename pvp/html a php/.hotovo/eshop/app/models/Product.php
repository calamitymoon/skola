<?php

namespace models;

class Product extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'products';
    protected $fieldConf = [
        'name' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'price' => [
            'type' => 'INT4',
            'required' => true
        ],
        'stock' => [
            'type' => 'INT4',
            'required' => true
        ],
        'created_at' => [
            'type' => 'TIMESTAMP',
            'default' => \DB\SQL\Schema::DF_CURRENT_TIMESTAMP
        ]
    ];
}