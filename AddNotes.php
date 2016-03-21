#!/usr/bin/php
<?php

require_once("logindb.php.inc");
//require_once("AddNotes.php.inc");

Echo "Enter username ".PHP_EOL;
$handle=fopen("php://stdin","r");
$line=fgets($handle);
$username=trim($line);

Echo "Enter Password ".PHP_EOL;
//$handle=fopen("php://stdin","r");
$line=fgets($handle);
$password=trim($line);

Echo "Enter Role ".PHP_EOL;
//$handle=fopen("php://stdin","r");
$line=fgets($handle);
$userRole=trim($line);


$login = new loginDB("logindb.ini");
   if ($login->addNotes($username,$password,$userRole))
   
   {
      echo "notes added".PHP_EOL;
   }
   else 
   {
      echo "notes added".PHP_EOL;
   }
   
   


?>