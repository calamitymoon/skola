<?php

namespace models;

class OrderItem extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'order_items';
    protected $fieldConf = [
        'order_id' => [
            'type' => 'INT4',
            'required' => true
        ],
        'product_id' => [
            'type' => 'INT4',
            'required' => true
        ],
        'quantity' => [
            'type' => 'INT4',
            'required' => true
        ],
        'unit_price' => [
            'type' => 'INT4',
            'required' => true
        ]
    ];

    public function product()
    {
        return $this->hasone('\models\Product', 'id');
    }

    public function order()
    {
        return $this->hasone('\models\Order', 'id');
    }
}