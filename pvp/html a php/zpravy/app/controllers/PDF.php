<?php

namespace controllers;

class PDF extends AbstractController
{
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
}