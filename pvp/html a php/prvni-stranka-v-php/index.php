<?php

echo "Hello World!";
echo "<h1>toto je moje prvni stranka</h1>";

for ($i = 0; $i < 10; $i++) {
    echo "Cislo: $i<br>";
}

$pole[0] = "prvni";
$pole[1] = "druhy";
$pole[2] = "treti";

foreach ($pole as $prvek) {
    echo "Prvek: $prvek<br>";
}

?>>