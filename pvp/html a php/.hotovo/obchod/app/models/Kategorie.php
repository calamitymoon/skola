<?php

namespace models;

class Kategorie extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'kategorie';

    protected $fieldConf = [
        'vsechny' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => false
        ]
    ];
}