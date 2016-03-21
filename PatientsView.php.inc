<?php
class loginDB
{
   private $db;
   private $ini;
   
     private function saltPassword($password)
   {
	$salt = $this->ini['loginDB']['salt'];
	return substr(sha1($password.$salt),10,-10);
   }
   public function __construct($iniFile)
   {
	$this->ini = parse_ini_file($iniFile,true);
	$host = $this->ini['loginDB']['host'];
	$user = $this->ini['loginDB']['user'];
	$password = $this->ini['loginDB']['password'];
	$database = $this->ini['loginDB']['database'];
	$this->db = new mysqli($host,$user,$password,$database);
	if ($this->db->connect_errno > 0)
	{
		echo __FILE__.":".__LINE__.": failed to connect to db, re: ".$this->db->connect_error.PHP_EOL;
		exit(0);
	}
   }
   public function __destruct()
   {
	$this->db->close();
   }

   public function checkIfUserExists($patientID,$fname)
   {
	$patientID = $this->db->real_escape_string($patientID);
	$fname = $this->db->real_escape_string($fname);
	$query = "select patientID,fname from PatientsDetails where patientID = '$patientID' and fname= '$fname';";
        $results = $this->db->query($query);
	$row = $results->fetch_assoc();
	if ($row['fname'] === $fname)
        {
		return true;
	}
        return false;
   }
  
          

     public function PatientsView($patientID,$fname)
   {
   
   if ($this->checkIfUserExists($patientID,$fname) == true)
        {
	
	Echo "Enter patients last name ".PHP_EOL;
      $handle=fopen("php://stdin","r");
      $line=fgets($handle);
      $lname=trim($line);
	}
	else{
	Echo "Wrong Details provided".PHP_EOL;
	return;
	}
	
	$patientID = $this->db->real_escape_string($patientID);
	$fname = $this->db->real_escape_string($fname);
	//$lname = $this->db->real_escape_string($lname);
	$query = "select patientID,fname,lname,address,phone,notes from PatientsDetails where patientID='$patientID';";
	$results = $this->db->query($query);
	while($list=$results->fetch_assoc())
	{
	
	echo "".$list['patientID'].PHP_EOL;
	echo "".$list['fname'].PHP_EOL;
	echo "".$list['lname'].PHP_EOL;
	echo "".$list['address'].PHP_EOL;
	echo "".$list['phone'].PHP_EOL;
	echo "".$list['notes'].PHP_EOL;
	}
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return;
        }
      }

}
?>

