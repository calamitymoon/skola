<?php

namespace models;

class User extends \DB\Cortex
{
    protected $db = 'DB',
              $table = 'user';

    protected $fieldConf=[
        'nick'=>[
            'type'=>'VARCHAR128',
            'required'=>true,
            'unique'=>true,
            'nullable'=>false,
            'index'=>true
        ],
        'name'=>[
            'type'=>'VARCHAR128',
            'required'=>true
        ],
        'surname'=>[
            'type'=>'VARCHAR128',
            'required'=>true
        ],
        'email'=>[
            'type'=>'VARCHAR256',
            'required'=>true,
            'unique'=>true,
            'nullable'=>false,
            'index'=>true
        ],
        'password'=>[
            'type'=>'VARCHAR256',
            'required'=>true,
            'nullable'=>false
        ],
        'send_message'=>[
            'has-many'=>['models\Message','sender']
        ],
        'receive_message'=>[
            'has-many'=>['models\Message','recepient']
        ],
    ];

    public function set_password($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }
}