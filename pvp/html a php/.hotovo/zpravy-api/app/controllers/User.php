<?php

namespace controllers;

class User
{
    public function register(\Base $base)
    {
        $data = json_decode($base->get('BODY'), true);
        error_log("Register endpoint called with data: " . json_encode($data));
        
        $user = new \models\User();
        try{
            $user->copyfrom($data);
            $user->save();
            $base->status(201);
            echo json_encode(['message'=>'Uzivatel vytvoren.']);
        }catch (\Exception $e){
            $base->error(500, 'Chyba pri vytvareni uzivatele: ' . $e->getMessage() . '.');
        }
    }

    public function login(\Base $base)
    {
        $data = json_decode($base->get('BODY'), true);
        error_log("Login endpoint called with data: " . json_encode($data));
        
        $user = new \models\User();
        $user->load(['email = ?', $data['email']]);
        
        if ($user->dry() || !password_verify($data['password'], $user->password)) {
            $base->error(401, 'Neplatny email nebo heslo.');
            return;
        }

        echo json_encode(['message' => 'Prihlaseni uspesne.']);
    }

    public function index(\Base $base)
    {
        $users = new \models\User();
        try {
            $users->fields(['nick']);
            $data = $users->afind();
            $base->status(200);
            header('Content-Type: application/json');
            echo json_encode($data);
            // var_dump($vsichni);
        } catch (\Exception $e) {
            $base->error(500, 'Chyba pri nacitani uzivatelu: ' . $e->getMessage() . '.');
        }
    }
}