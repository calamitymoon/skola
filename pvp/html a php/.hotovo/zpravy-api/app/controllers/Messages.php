<?php

namespace controllers;

class Message
{
    public function store(\Base $base)
    {
        $data = json_decode($base->get('BODY'), true);
        $message = new \models\Message();
        try{
            $message->copyfrom($data);
            $message->save();
            if (isset($message->id)) {
                $base->status(201);
                echo json_encode(['message'=>'Message created, id: ' . $message->id]);
            } else {
                $base->error(500, 'Error saving message');
            }
        }catch (\Exception $e){
            $base->error(500, 'Error saving message: ' . $e->getMessage());
        }
    }
}