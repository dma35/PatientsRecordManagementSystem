#!/usr/bin/php
<?php

require_once("logindb.php.inc");
//require_once("AddNotes.php.inc");

Echo "Enter username ".PHP_EOL;
$handle=fopen("php://stdin","r");
$line1=fgets($handle);
$username=trim($line1);

Echo "Enter Password ".PHP_EOL;
//$handle=fopen("php://stdin","r");
$line2=fgets($handle);
$password=trim($line2);

Echo "Enter Role ".PHP_EOL;
//$handle=fopen("php://stdin","r");
$line3=fgets($handle);
$userRole=trim($line3);


$login = new loginDB("logindb.ini");
$login->IndividualRecord($username,$password,$userRole);
   
  

?>