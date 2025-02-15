<?php

namespace controllers;

class Uzivatel extends AbstractController
{
    public function getVysledkyAnkety(\Base $base)
    {
        $vysledkyModel = new \models\AnketaVysledky();

        $vysledky = [];
        $hlasyPerAnketa = [];

        $vysledek = $vysledkyModel->find();
        if ($vysledek){
            foreach ($vysledek as $radek) {
                if (!isset($hlasyPerAnketa[$radek->anketa_id])) {
                    $hlasyPerAnketa[$radek->anketa_id] = 0;
                }
                $hlasyPerAnketa[$radek->anketa_id] += $radek->pocet;
                $vysledky[] = $radek->cast();
            }

            foreach ($vysledky as &$radek) {
                $radek['procenta'] = ($radek['pocet'] / $hlasyPerAnketa[$radek['anketa_id']]) * 100;
            }
        } else {
            // jeste nikdo nehlasoval v anketach
        }
        
        $base->set('moznosti', $vysledky);
        $base->set('title', 'Výsledky ankety');
        $base->set('content', '/uzivatel/vysledky.html');
        echo \Template::instance()->render('index.html');
    }

    public function getAnketa(\Base $base)
    {
        $ankety = new \models\Ankety();
        $base->set('ankety', $ankety->find());
        $base->set('title', 'Anketa');
        $base->set('content', '/uzivatel/anketa.html');
        echo \Template::instance()->render('index.html');
    }

    public function postAnketa(\Base $base)
    {
        $vysledky = new \models\AnketaVysledky();
        $anketa_id = $base->get('POST.anketa_id');
        $moznost = $base->get('POST.moznost');
        $otazka = $base->get('POST.otazka_ankety');
        $odesilatel = $base->get('SESSION.uid');

        // Check if the user has already voted in this survey
        if ($base->exists('SESSION.hlasoval') && in_array($anketa_id, $base->get('SESSION.hlasoval'))) {
            echo "<script>
                alert('V této anketě jsi již hlasoval.');
                window.location.href = '/zpravy/user/surveys';
            </script>";
            return;
        }

        $existujiciVysledek = $vysledky->findone(['anketa_id = ? AND moznost = ?', $anketa_id, $moznost]);

        if ($existujiciVysledek) {
            $existujiciVysledek->pocet += 1;
            $vysledky = $existujiciVysledek;
        } else {
            $vysledky->anketa_id = $anketa_id;
            $vysledky->moznost = $moznost;
            $vysledky->pocet = 1;
        }
        $vysledky->odesilatel = $odesilatel;
        $vysledky->otazka = $otazka;
        
        $vysledky->save();

        $jiz_hlasovane_ankety = $base->exists('SESSION.hlasoval') ? $base->get('SESSION.hlasoval') : [];
        $jiz_hlasovane_ankety[] = $anketa_id;
        $base->set('SESSION.hlasoval', $jiz_hlasovane_ankety);

        $base->reroute('/user/surveys');
    }
    
    public function getList(\Base $base)
    {
        $base->set('title', 'Seznam uzivatelu');
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('users', $users->find());
        $base->set('content', '/uzivatel/list.html');
        echo \Template::instance()->render('index.html');
    }
    
    public function getUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $base->set('uzivatel', $uzivatel->findone(["id= ?", $base->get('SESSION.uid')]));
        $base->set('title', 'Úprava profilu');
        $base->set('content', '/uzivatel/upravit.html');
        echo \Template::instance()->render('index.html');
    }

    public function postUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel->load(["id=?", $base->get('SESSION.uid')]);
        $uzivatel->copyfrom($base->get('POST'));
        $uzivatel->avatar = $this->ulozAvatar($base);
        $uzivatel->save();
        $base->reroute('/');
    }

    public function getProfil(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $base->get('SESSION.uid')]);

        if ($uz) {
            $base->set('uzivatel', $uz);
            $base->set('title', 'Profil uzivatele');
            $base->set('content', '/uzivatel/profil.html');
            echo \Template::instance()->render('index.html');
        } else {
            $base->reroute('/');
        }
    }

    public function getAvatar(\Base $base)
    {
        $base->set('title', 'Nahrat avatara');
        $base->set('content', '/uzivatel/avatar.html');
        echo \Template::instance()->render('index.html');
    }

    public function postAvatar(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $base->get('SESSION.uid')]);
        $base->set('SESSION.avatar', $uz->avatar);

        if ($uz) {
            $souborAvataru = $_FILES['avatar'];
            $nazevAvataru = $uz->nick . '.png';
            $cesta_k_avataru = '/zpravy/assets/avatars/' . $nazevAvataru;

            if ($souborAvataru['error'] === UPLOAD_ERR_OK) {
                move_uploaded_file($souborAvataru['tmp_name'], $_SERVER['DOCUMENT_ROOT'] . $cesta_k_avataru);

                $uz->avatar = $cesta_k_avataru;
                $uz->save();
                $base->reroute('/user/profile');
            } else {
                echo "<script>
                    alert('Chybička se bloudila.');
                    window.location.href = '/zpravy/user/add';
                </script>";
                $base->reroute('/user/avatar');
            }
        } else {
            $base->reroute('/');
        }
    }

    public function getOdstranitAvatara(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $base->get('SESSION.uid')]);

        if ($uz) {
            $uz->avatar = null;
            $uz->save();
            
            $nick = $uz->nick;
            $cesta_k_avataru = $_SERVER['DOCUMENT_ROOT'] . '/zpravy/assets/avatars/' . $nick . '.png';
            if (file_exists($cesta_k_avataru)) {
                unlink($cesta_k_avataru);
            }
            
            $base->reroute('/user/profile');
        }

        $base->reroute('/user/profile');
    }

    public function postZamknout(\Base $base)
    {
        $data = json_decode($base->get('BODY'),true);
        $idUzivatele = $data["id"];
        header('Content-Type: application/json');
        $uzivatel = new \models\Uzivatel();
        $uzivatel->load(["id=?", $idUzivatele]);

        if($uzivatel->dry()){
            echo json_encode(["error" => "Uzivatel nenalezen."]);
            return;
        }
        if($uzivatel->locked){
            $uzivatel->locked = 0;
        }else{
            $uzivatel->locked = 1;
        }
        $uzivatel->save();
        echo json_encode(["success" => "Stav zmenen."]);
        // $base->reroute('/user/list');
    }
        // $uzivatel = new \models\Uzivatel();
        // $uz = $uzivatel->findone(['id = ?', $base->get('PARAMS.id')]);

        // if ($uz && !$uz->locked) {
        //     $uz->locked = true;
        //     $uz->save();
        //     $base->reroute('/user/list');
        // } else if ($uz && $uz->locked) {
        //     $uz->locked = false;
        //     $uz->save();
        //     $base->reroute('/user/list');
        // } else {
        //     $base->reroute('/');
        // }
}