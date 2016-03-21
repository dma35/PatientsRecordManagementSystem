NOT DONE

<?php

class classesDB
{
   private $db;
   public function __construct()
   {
	$this->db = new mysqli("localhost","root","doyinsola","PatientReg");
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
  	return;
        }
  
   public function AddPatient($fname,$lname,$address,$phone)
   {
	$fname = $this->db->real_escape_string($fname);
	$lname = $this->db->real_escape_string($lname);
	$address = $this->db->real_escape_string($address);
	$phone = $this->db->real_escape_string($phone);
	$query = "insert into PatientsDetails(fname,lname,address,phone) values ('$fname','$lname','$address','$phone');";
	echo "executing query: \n".$query.PHP_EOL;
	$results = $this->db->query($query);
	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
   }
}
?>
