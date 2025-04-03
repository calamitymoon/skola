<?php

namespace controllers;

class Maily
{
    public function getZapomenuteHeslo(\Base $base)
    {
        $base->set('title', 'Zapomenuté heslo');
        $base->set('content', 'static/zapomenute_heslo.html');
        echo \Template::instance()->render('index.html');
    }

    public function postZapomenuteHeslo(\Base $base)
    {
        $email = $base->get('POST.email');
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['email=?', $email]);
        if ($uz) {
            $nove_heslo = new \models\NoveHeslo();
            $existing = $nove_heslo->findone(['id_uzivatele=?', $uz->id]);
            if ($existing) {
                $existing->erase();
            }
            
            $token = bin2hex(random_bytes(16));
            $nove_heslo = new \models\NoveHeslo();
            $nove_heslo->id_uzivatele = $uz->id;
            $nove_heslo->hash = $token;
            
            $platnost = new \DateTime();
            $platnost->setTimezone(new \DateTimeZone('Europe/Prague'));
            $platnost->modify('+1 hour');
            $nove_heslo->platnost = $platnost->format('Y-m-d H:i:s');
            
            $nove_heslo->save();
            self::send_reset_password($email, $token);
            \Flash::instance()->addMessage('Odkaz pro resetování hesla byl odeslán na váš email.', 'success');
        } else {
            \Flash::instance()->addMessage('Email nebyl nalezen.', 'danger');
        }
        $base->reroute('/');
    }

    public function getResetovatHeslo(\Base $base)
    {
        $token = $base->get('GET.token');
        if (!$token) {
            \Flash::instance()->addMessage('Chybějící token pro reset hesla.', 'danger');
            $base->reroute('/zapomenute-heslo');
            return;
        }

        // kontrola platnosti tokenu
        $nove_heslo = new \models\NoveHeslo();
        
        $tokenExistuje = $nove_heslo->findone(['hash=?', $token]);
        if ($tokenExistuje) {
            $vyprsi = new \DateTime($tokenExistuje->platnost);
            $ted = new \DateTime();
            
            $ted->setTimezone(new \DateTimeZone('Europe/Prague'));
            
            if ($ted < $vyprsi) {
                $base->set('token', $token);
                $base->set('title', 'Resetování hesla');
                $base->set('content', 'static/resetovat_heslo.html');
                echo \Template::instance()->render('index.html');
                return;
            } else {
                $emailStatus = new \models\EmailStatus();
                $status = $emailStatus->findone(['hash=?', $token]);
                if ($status && !$status->expirovano) {
                    $status->expirovano = date('Y-m-d H:i:s');
                    $status->save();
                }
                
                \Flash::instance()->addMessage('Token pro reset hesla vypršel.', 'danger');
                $base->reroute('/zapomenute-heslo');
                return;
            }
        }

        \Flash::instance()->addMessage('Neplatný token pro reset hesla.', 'danger');
        $base->reroute('/zapomenute-heslo');
    }

    public function postResetovatHeslo(\Base $base)
    {
        $token = $base->get('POST.token');
        $heslo = $base->get('POST.heslo');
        $heslo_confirm = $base->get('POST.heslo_confirm');

        if (empty($heslo) || empty($heslo_confirm)) {
            \Flash::instance()->addMessage('Vyplňte heslo a jeho potvrzení.', 'danger');
            $base->reroute('/resetovat-heslo?token=' . $token);
            return;
        }

        if ($heslo !== $heslo_confirm) {
            \Flash::instance()->addMessage('Hesla se neshodují.', 'danger');
            $base->reroute('/resetovat-heslo?token=' . $token);
            return;
        }

        $nove_heslo = new \models\NoveHeslo();
        $reset = $nove_heslo->findone(['hash=? AND platnost>NOW()', $token]);
        
        if (!$reset) {
            \Flash::instance()->addMessage('Neplatný nebo expirovaný token pro reset hesla.', 'danger');
            $base->reroute('/zapomenute-heslo');
            return;
        }

        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['id=?', $reset->id_uzivatele]);
        
        if ($uz) {
            $uz->heslo = $heslo;
            $uz->save();
            
            // odstranime token z databaze
            $reset->erase();
            
            $emailStatus = new \models\EmailStatus();
            $status = $emailStatus->findone(['hash=?', $token]);
            if ($status) {
                $status->resetovano = date('Y-m-d H:i:s');
                $status->save();
            }

            \Flash::instance()->addMessage('Vaše heslo bylo úspěšně změněno. Nyní se můžete přihlásit.', 'success');
            $base->reroute('/login');
        } else {
            \Flash::instance()->addMessage('Nepodařilo se najít uživatele.', 'danger');
            $base->reroute('/zapomenute-heslo');
        }
    }

    public static function send_reset_password($cil, $token)
    {
        $f3 = \Base::instance();
        $mail = new \Mailer();
        $mail->addTo($cil);
        
        $subject = 'Resetovaní hesla';
        $scheme = isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] !== 'off' ? 'https' : 'http';
        $baseURL = $scheme . '://' . $_SERVER['HTTP_HOST'];

        if (dirname($_SERVER['SCRIPT_NAME']) != '/') {
            $baseURL .= dirname($_SERVER['SCRIPT_NAME']);
        }
        
        $trackingURL = $baseURL . '/track-email?token=' . $token;
        $link = $baseURL . '/resetovat-heslo?token=' . $token;

        $textContent = 'Pro resetování hesla použijte tento odkaz: ' . $link;
        $mail->setText($textContent);
        
        $htmlContent = 'Pro resetování hesla klikněte <a href="' . $link . '">zde</a> nebo na tento odkaz: <a href="' . $link . '">' . $link . '</a>';
        $htmlContent .= '<img src="' . $trackingURL . '" width="1" height="1" alt="" style="display:block; position:absolute; visibility:visible !important;">';
        $mail->setHTML($htmlContent);
        
        $mail->send($subject);
        
        $uzivatel = new \models\Uzivatel();
        $uz = $uzivatel->findone(['email=?', $cil]);
        
        if ($uz) {
            $status = new \models\EmailStatus();
            $status->id_uzivatele = $uz->id;
            $status->hash = $token;
            $status->email = $cil;
            $status->odeslano = date('Y-m-d H:i:s');
            
            $platnost = new \DateTime();
            $platnost->setTimezone(new \DateTimeZone('Europe/Prague'));
            $platnost->modify('+1 hour');
            $status->platnost = $platnost->format('Y-m-d H:i:s');
            
            $status->save();
        }
    }

    public static function traceMail($status, $email)
    {
        if ($email->get('Subject') === 'Resetovaní hesla') {
            $body = $email->get('HTML');
            if (preg_match('/resetovat-heslo\?token=([a-f0-9]+)/', $body, $matches)) {
                $token = $matches[1];
                
                $toField = $email->get('To');
                preg_match('/<([^>]+)>/', $toField, $emailMatches);
                $to = !empty($emailMatches) ? $emailMatches[1] : $toField;
                
                $emailStatus = new \models\EmailStatus();
                $status = $emailStatus->findone(['hash=?', $token]);
                
                if (!$status) {
                    $uzivatel = new \models\Uzivatel();
                    $uz = $uzivatel->findone(['email=?', $to]);
                    
                    if ($uz) {
                        $status = new \models\EmailStatus();
                        $status->id_uzivatele = $uz->id;
                        $status->hash = $token;
                        $status->email = $to;
                        $status->odeslano = date('Y-m-d H:i:s');
                        
                        $platnost = new \DateTime();
                        $platnost->setTimezone(new \DateTimeZone('Europe/Prague'));
                        $platnost->modify('+1 hour');
                        $status->platnost = $platnost->format('Y-m-d H:i:s');
                        
                        $status->save();
                    }
                }
            }
        }
    }

    public function trackEmail(\Base $base)
    {
        $token = $base->get('GET.token');
        if ($token) {
            $emailStatus = new \models\EmailStatus();
            
            $status = $emailStatus->findone(['LOWER(hash)=LOWER(?)', $token]);
            
            if ($status) {
                $status->zobrazeno = date('Y-m-d H:i:s');
                $status->save();
                error_log("Email tracking: Email with token {$token} marked as viewed");
            } else {
                error_log("Email tracking: Token not found in database: {$token}");
            }
        } else {
            error_log("Email tracking: No token provided in request");
        }
        
        header('Cache-Control: no-store, no-cache, must-revalidate, max-age=0');
        header('Cache-Control: post-check=0, pre-check=0', false);
        header('Pragma: no-cache');
        header('Expires: 0');
        header('Content-Type: image/gif');
        echo base64_decode('R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7');
        exit;
    }
}