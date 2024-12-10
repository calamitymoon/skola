<?php

namespace models;

class Potvrzeni extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'vytvorena_potvrzeni';

    protected $fieldConf = [
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'prijmeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'datumnarozeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'adresa' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'skolnirok' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'trida' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'formavzdelani' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'odbornaskola' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'datumodeslani' => [
            'type' => 'VARCHAR128',
            'required' => true
        ]
    ];
}