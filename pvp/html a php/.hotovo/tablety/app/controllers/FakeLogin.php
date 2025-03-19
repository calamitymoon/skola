<?php

namespace controllers;

class FakeLogin
{
    public function getAdmin(\Base $base)
    {
        $base->set('SESSION.id', '1');
        $base->set('SESSION.jmeno', 'Administrátor');
        $base->set('SESSION.prihlasen', true);
        $base->set('SESSION.admin', true);
        $base->reroute('/');
    }
    
    public function getUser(\Base $base)
    {
        $base->set('SESSION.id', '2');
        $base->set('SESSION.jmeno', 'Michal Moc');
        $base->set('SESSION.prihlasen', true);
        $base->reroute('/');
    }

    public function getLogout(\Base $base)
    {
        $base->clear('SESSION');
        $base->reroute('/');
    }
}