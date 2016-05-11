<?php
//phpinfo();
$uri="<?php
//phpinfo();
$uri="<?php
//phpinfo();
$uri="mongodb://patientreg:march23@ds017862.mlab.com:17862/patient_record_system";
try{
$conn=new Mongoclient($uri);
$db=$conn->patient_record_system;
$collection=$db->patientreg;
echo"Enter patient id".PHP_EOL;
$handle=fopen("php://stdin","r");
$line7=fgets($handle);
$patientid=trim($line7);
echo " Enter your First Name ".PHP_EOL;
$line3 = fgets($handle);
$firstname=trim($line3);
echo " Enter your Last Name ".PHP_EOL;
$line4 = fgets($handle);
$lastname=trim($line4);
echo " Enter your Apt No ".PHP_EOL;
$line5 = fgets($handle);
$aptno=trim($line5);
echo " Enter your street ".PHP_EOL;
$line6 = fgets($handle);
$street=trim($line6);
echo " Enter your city ".PHP_EOL;
$handle = fopen("php://stdin","r");
$line = fgets($handle);
$city=trim($line);
echo " Enter your state ".PHP_EOL;
$line2 = fgets($handle);
$state=trim($line2);





$userdetails=array('patientid'=> $patientid,
		'firstname'=>$firstname,
	 	'lastname'=>$lastname,
		'aptno'=>$aptno,
		'street'=>$street,
                'city'=>$city ,
                'state'=>$state ,
                 );
$collection->insert($patientreg);
echo "Connection successful".PHP_EOL;
}
catch(MongoConnectionException $e)
{
die('Error connecting to MongoDBserver '.$e->getMessage());
}


?>";

