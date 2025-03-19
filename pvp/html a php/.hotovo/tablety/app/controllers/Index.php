<?php

namespace controllers;

class Index
{
    public function getVypujcit(\Base $base)
    {
        $base->set('title', 'Půjčka tabletu');
        $base->set('content', '/pujcka/vypujcit.html');

        $base->set('periods', [
            '0' => ['start' => '7:05', 'end' => '7:50'],
            '1' => ['start' => '8:00', 'end' => '8:45'],
            '2' => ['start' => '8:50', 'end' => '9:35'],
            '3' => ['start' => '9:55', 'end' => '10:40'],
            '4' => ['start' => '10:50', 'end' => '11:35'],
            '5' => ['start' => '11:45', 'end' => '12:30'],
            '6' => ['start' => '12:35', 'end' => '13:20'],
            '7' => ['start' => '13:25', 'end' => '14:10'],
            '8' => ['start' => '14:15', 'end' => '15:00'],
            '9' => ['start' => '15:05', 'end' => '15:50'],
        ]);

        $base->set('days', ['po', 'út', 'st', 'čt', 'pá']);

        $base->set('tridyGroups', [
            [
                '1A', '2A', '3A', '4A'
            ],
            [
                '1B', '2B', '3B', '4B'
            ],
            [
                '1Z', '2Z', '3Z', '4Z'
            ],
            [
                '1T', '2T', '3T', '4T'
            ]
        ]);

        echo \Template::instance()->render('index.html');
    }

    public function postVypujcit(\Base $base)
    {
        $jmeno = $base->get('POST.jmeno');
        $tridy = json_encode($base->get('POST.tridy'));
        $vypujceni = $base->get('POST.startTime');
        $vraceni = $base->get('POST.endTime');
        $denvypujceni = $base->get('POST.dayName');
        $poznamka = $base->get('POST.poznamka');

        $pujcovna = new \models\Pujcovna();
        $pujcovna->jmeno = $jmeno;
        $pujcovna->tridy = $tridy;
        $pujcovna->vypujceni = $vypujceni;
        $pujcovna->vraceni = $vraceni;
        $pujcovna->denvypujceni = $denvypujceni;
        $pujcovna->poznamka = $poznamka;
        $pujcovna->save();

        $base->reroute('/seznam');
    }

    public function getSeznam(\Base $base)
    {
        $base->set('title', 'Seznam rezervací tabletů');
        $base->set('content', '/pujcka/seznam.html');

        $pujcovna = new \models\Pujcovna();
        $base->set('pujcovna', $pujcovna->find());

        echo \Template::instance()->render('index.html');
    }
}