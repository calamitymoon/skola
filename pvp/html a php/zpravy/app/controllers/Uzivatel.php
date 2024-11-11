<?php

namespace controllers;

class Uzivatel
{
    public function getRegistrace(\Base $base)
    {
        $base->set('title', 'Registrace');
        $base->set('content', '/uzivatel/registrace.html');
        echo \Template::instance()->render('index.html');
    }

    public function postRegistrace(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();        
        $existujiciEmail = $uzivatel->findone(['email=?', $base->get('POST.email')]);
        $existujiciNick = $uzivatel->findone(['nick=?', $base->get('POST.nick')]);

        if ($existujiciEmail) {
            echo "<script>
                    alert('Zadaný email je již zaregistrován.');
                    window.location.href = '/zpravy/user/add';
                </script>";
        } elseif ($existujiciNick) {
            echo "<script>
                    alert('Zadaný nick je již zaregistrován.');
                    window.location.href = '/zpravy/user/add';
                </script>";
        } else {
            $uzivatel->copyfrom($base->get('POST'));
            $uzivatel->save();
            $base->reroute('/user/login');
        }
    }

    public function getLogin(\Base $base)
    {
        $base->set('title', 'Přihlášení');
        $base->set('content', '/uzivatel/login.html');
        echo \Template::instance()->render('index.html');
    }

    public function postLogin(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['email=?', $base->get('POST.email')]);
        if ($uz && $uz->heslo === $base->get('POST.heslo')) {
            $base->set('SESSION.uid', $uz->id);
            $base->set('SESSION.avatar', $uz->avatar);
            $base->set('SESSION.nick', $uz->nick);
            $base->set('SESSION.jmeno', $uz->jmeno);
            $base->set('SESSION.prijmeni', $uz->prijmeni);
            $base->set('SESSION.email', $uz->email);

            $uz = $uzivatel->findone(['id = ?', $base->get('SESSION.uid')]);
            $nazevAvataru = $uz->nick . '.png';
            $cesta_k_avataru = '/zpravy/assets/avatars/' . $nazevAvataru;
            $uz->avatar = $cesta_k_avataru;
            $uz->save();

            $base->reroute('/');
        } else {            
            $base->reroute('/user/login');
        }
    }

    public function getList(\Base $base)
    {
        $base->set('title', 'Seznam uzivatelu');
        $users = new \models\Uzivatel(); // vyrobit model uzivatelu
        $base->set('users', $users->find());
        $base->set('content', '/uzivatel/list.html');
        echo \Template::instance()->render('index.html');
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION.id');
        $base->clear('SESSION.jmeno');
        $base->clear('SESSION.uid');
        $base->reroute('/');
    }
    
    public function getUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id = ?', $base->get('PARAMS.id')]);
        
        if ($uz) {
            $base->set('uzivatel', $uz);
            $base->set('title', 'Upravit uzivatele');
            $base->set('content', '/uzivatel/upravit.html');
            echo \Template::instance()->render('index.html');
        } else {
            $base->reroute('/');
        }
    }

    public function postUpravit(\Base $base)
    {
        $uzivatel = new \models\Uzivatel();
        $uzivatel->load($base->get('PARAMS.id'));
        $uzivatel->copyFrom('POST');
        $uzivatel->save();
        $base->reroute('/user/list');
        if ($uz->load(['id = ?', $id])) {
            $uz->id = $_POST['id'];
            $uz->prezdivka = $_POST['prezdivka'];
            $uz->jmeno = $_POST['jmeno'];
            $uz->prijmeni = $_POST['prijmeni'];
            $uz->email = $_POST['email'];
            $uz->heslo = $_POST['heslo'];
            
            $mapper->save();
        } else {
            echo "uzivatel neexistuje";
        }
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
}