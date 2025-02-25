<?php

namespace models;

class Customer extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'customers';
    protected $fieldConf = [
        'name' => [
            'type' => 'VARCHAR256',
            'required' => true
        ],
        'email' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true
        ],
        'created_at' => [
            'type' => 'TIMESTAMP',
            'default' => \DB\SQL\Schema::DF_CURRENT_TIMESTAMP
        ]
    ];

    public function orders()
    {
        return $this->hasmany('\models\Order', 'customer_id');
    }
}