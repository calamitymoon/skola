<?php

namespace models;

class Obchod extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'obchod';

    protected $fieldConf = [
        'typ' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        'kategorie' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'nullable' => false
        ],
        // 'pobocky' => [
        //     'type' => 'VARCHAR256',
        //     'required' => true,
        //     'nullable' => false
        // ],
    ];
    
    protected $relConf = [
        'pobocky' => [
            'has-many' => [\models\Pobocka::class, 'obchod']
        ]
    ];
}