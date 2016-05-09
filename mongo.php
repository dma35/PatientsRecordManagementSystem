<?php
$uri="mongodb://Doyinsola:march23@ds017862.mlab.com:17862/patient_record_system";
try{
$connection =new Mongoclient($uri);
echo"Connection to Server Successful".PHP_EOL;
}
catch(MongoConnectionException $e)
{
die('Error connecting to mongodb server'.$e->getMessage());
}
$db = $connection -> patient_record_system;
echo"Connection to Database Successful".PHP_EOL;


?>