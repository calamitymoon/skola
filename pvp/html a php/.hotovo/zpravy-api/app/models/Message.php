<?php

namespace models;

class Message extends \DB\Cortex
{
    protected $db = 'DB',
        $table = 'message';

    protected $fieldConf=[
        'subject'=>[
            'type'=>'VARCHAR128',
            'required'=>true,
            'nullable'=>false
        ],
        'content'=>[
            'type'=>'TEXT',
            'required'=>true,
            'nullable'=>false
        ],
        'recepient'=>[
            'belongs-to-one'=>'models\User',
            'required'=>true,
            'nullable'=>false
        ],
        'created'=>[
            'type'=>'TIMESTAMP',
            'default'=>\DB\SQL\Schema::DF_CURRENT_TIMESTAMP
        ],
        'read'=>[
            'type'=>'BOOLEAN',
            'default'=>0
        ],
        'sender'=>[
            'belongs-to-one'=>'models\User',
            'required'=>true,
            'nullable'=>false
        ],
    ];
}