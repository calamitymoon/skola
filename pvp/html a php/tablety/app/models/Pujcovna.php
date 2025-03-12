<?php

namespace models;

class Pujcovna extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'pujcovna';

    protected $fieldConf = [
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'tridy' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => false
        ],
        'denvypujceni' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'vypujceni' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'vraceni' => [
            'type' => 'VARCHAR128',
            'required' => false,
            'nullable' => false
        ],
        'poznamka' => [
            'type' => 'TEXT',
            'required' => false,
            'nullable' => true
        ]
    ];
}