<?php

namespace controllers;

class Soubor extends AbstractController
{
    public function saveFile(\Base $base)
    {
        $web = \Web::instance();
        $overwrite = false;
        $slug = true;

        $files = $web->receive(function($file,$formFieldName){
                var_dump($file);
                // if($file['size'] > (2 * 1024 * 1024)) // if bigger than 2 MB
                //     return false;
                return true;
            },
            $overwrite,
            $slug
        );

        var_dump($files);
        
        foreach (array_keys($files) as $file) {
            $soubor = new \models\Soubor();

            $soubor->cesta = $file;
            $soubor->nazev = $file;
            $soubor->odesilatel = $base->get('SESSION.nick');
            $soubor->save();
        }
        
        $base->reroute('/');
    }

    public function getFile(\Base $base)
    {
        $base->set('content', '/soubory/nahrat.html');
        echo \Template::instance()->render('index.html');
    }
}