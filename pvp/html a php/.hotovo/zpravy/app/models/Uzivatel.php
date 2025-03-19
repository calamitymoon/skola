<?php

namespace models;

class Uzivatel extends \DB\Cortex
{
    protected $db = 'DB';
    protected $table = 'uzivatel';

    protected $fieldConf = [
        'avatar' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'nullable' => true
        ],
        'nick' => [
            'type' => 'VARCHAR128',
            'required' => true,
            'unique' => true,
            'nullable' => false,
            'index' => true
        ],
        'jmeno' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'prijmeni' => [
            'type' => 'VARCHAR128',
            'required' => true
        ],
        'email' => [
            'type' => 'VARCHAR256',
            'required' => true,
            'unique' => true,
            'nullable' => false,
        ],
        'heslo'=>[
            'type'=> 'VARCHAR256',
            'required' => true,
            'nullable' => false
        ],
        'zpravy' => [
            'has-many' => ['models\Zpravy', 'id_from'],
        ],
        'locked' => [
            'type' => 'BOOLEAN',
            'default' => false
        ],
        'login' => [
            'has_many' => ['models\Login', 'uzivatel']
        ],
        'role' => [
            'belongs-to-one' => 'models\Role',
            'default' => '3'
        ]
    ];

    public function set_heslo($value)
    {
        return password_hash($value, PASSWORD_DEFAULT);
    }

    public function get_lastlogin()
    {
        $login = new \models\Login();
        return $login->findone(['uzivatel = ?', $this->id], ['order' => 'id DESC'])->last_login;
    }
}