<?php

namespace models;

class Type extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'type';
    protected $fieldConf = [
        'typ' => [
            'type' => 'VARCHAR256'
        ]
    ];
}