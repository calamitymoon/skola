<?php

namespace models;

class Typ extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'typ';

    protected $fieldConf = [
        'typy' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false
        ]
    ];
}