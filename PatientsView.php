#!/usr/bin/php
<?php

require_once("PatientsView.php.inc");
//require_once("AddNotes.php.inc");

Echo "Enter Patient ID".PHP_EOL;
$handle=fopen("php://stdin","r");
$line1=fgets($handle);
$patientID=trim($line1);


Echo "Enter First Name".PHP_EOL;
$handle=fopen("php://stdin","r");
$line1=fgets($handle);
$fname=trim($line1);

$login = new loginDB("logindb.ini");
$login->PatientsView($patientID,$fname);
   
  

?>