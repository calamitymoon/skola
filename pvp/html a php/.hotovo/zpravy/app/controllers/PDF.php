<?php

namespace controllers;

class PDF extends AbstractController
{
    public function strankaPDFprofilUzivatele(\Base $base)
    {
        $uzivatele = new \models\Uzivatel();
        $base->set('uzivatele', $uzivatele->find());
        $base->set('title', 'Profily uživatelů do PDF');
        $base->set('content', '/pdf/generace/profil.html');
        echo \Template::instance()->render('index.html');
    }

    public function vytvorPDF(\Base $base)
    {
        $base->set('title', 'PDF soubor');
        $uzivatele = new \models\Uzivatel();
        $base->set('users', $uzivatele->find());
        $pdf = new \Dompdf\Dompdf();
        $pdf->setPaper('A4', 'portrait');
        $pdf->loadHtml(\Template::instance()->render('/pdf/list.html'));
        $pdf->render();

        // do souboru (na serveru)
        file_put_contents($base->get('UPLOADS') . 'pdf/uzivatele.pdf', $pdf->output());

        header('Content-Type: application/pdf');
        echo base64_encode($pdf->stream("uzivatele.pdf", array("Attachment" => 0)));
        // $pdf->stream(); //   direct link je stazeni souboru
    }

    public function vytvorPDFprofilUzivatele(\Base $base)
    {
        $base->set('title', 'Profil uživatele do PDF');
        $uzivatele = new \models\Uzivatel();
        $idcko = $base->get('PARAMS.id');
        $vybranyUzivatel = $uzivatele->findone(['id = ?', $idcko]);

        $base->set('vybranyUzivatel', $vybranyUzivatel);
        $base->set('title', 'Profil uživatele do PDF');
        $pdf = new \Dompdf\Dompdf();
        $pdf->setPaper('A4', 'portrait');
        $pdf->loadHtml(\Template::instance()->render('/pdf/profil.html'));
        $pdf->render();
        
        file_put_contents($base->get('UPLOADS') . 'pdf/uzivatele' , $pdf->output());

        header('Content-Type: application/pdf');
        echo base64_encode($pdf->stream("profil.pdf", array("Attachment" => 0)));
    }
}