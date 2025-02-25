<?php

namespace models;

class Order extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'orders';
    protected $fieldConf = [
        'customer_id' => [
            'type' => 'INT4',
            'required' => true
        ],
        'total_price' => [
            'type' => 'INT4',
            'default' => 0.00
        ],
        'created_at' => [
            'type' => 'TIMESTAMP',
            'default' => \DB\SQL\Schema::DF_CURRENT_TIMESTAMP
        ]
    ];

    public function customer()
    {
        return $this->hasone('\models\Customer', 'id');
    }

    public function items()
    {
        return $this->hasmany('\models\OrderItem', 'order_id');
    }
}