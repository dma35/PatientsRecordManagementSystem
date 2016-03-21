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
 /* public function updateUserPassword($username,$oldPassword,$newPassword)
   {
   	if (!$this->validateUser($username,$oldPassword))
        {
		echo "cannot update Password, validation failed".PHP_EOL;
		$response = array(
			"message"=>"cannot update password, validation failed",
			"result"=>"false");
		return $response;
        }
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($newPassword));
	$query = "update login set password = '$password' where username ='$username');";
	$results = $this->db->query($query);
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return false;
        }
	return true;
   }*/
   public function checkUserPrivilegeLevel($username)
   {}
  
   public function enableUserAccount($username)
   {}
   public function checkIfUserExists($username)
   {
	$username = $this->db->real_escape_string($username);
	$query = "select username from login where username = '$username';";
        $results = $this->db->query($query);
	$row = $results->fetch_assoc();
	if ($row['username'] === $username)
        {
		return true;
	}
        return false;
   }
   public function validateUser($username,$password)
   {
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$query = "select username,password from login where username = '$username';";
        $results = $this->db->query($query);
	$row = $results->fetch_assoc();
	if ($row['password'] === $password)
	{
		return true;
	}
	return false;
   }
 
   public function addNewUser($username,$password,$userRole)
   {
	if ($this->checkIfUserExists($username) == true)
        {
		echo "cannot create new user $username, this user already exists!".PHP_EOL;
		return;
	}
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$userRole = $this->db->real_escape_string($userRole);
	$query = "insert into login (username,Password,userRole) values('$username','$password','$userRole');";
	$results = $this->db->query($query);
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return;
        }
   }
    public function disableUserAccount($username,$password,$userRole)
   {
    if ($this->checkIfUserExists($username) == true)
        {
		//echo "cannot create new user $username, this user already exists!".PHP_EOL;
		//return;
	
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$userRole = $this->db->real_escape_string($userRole);
	$query = "delete from login where username = '$username';";
	$results = $this->db->query($query);
	
	}
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return;
        }
   
   }
    public function addNotes($username,$password,$userRole)
   {
   
   if ($this->checkIfUserExists($username) == true)
        {
	Echo "Enter patients fname ".PHP_EOL;
      $handle=fopen("php://stdin","r");
      $line=fgets($handle);
      $fname=trim($line);
  
	Echo "Enter notes ".PHP_EOL;
     // $handle=fopen("php://stdin","r");
      $line=fgets($handle);
      $notes=trim($line);
		//return;
	}
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$userRole = $this->db->real_escape_string($userRole);
	$fname = $this->db->real_escape_string($fname);
	$notes = $this->db->real_escape_string($notes);
	$query = "update PatientsDetails set notes = '$notes' where fname ='$fname';";
	$results = $this->db->query($query);
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return;
        }
      }

       public function BrowseList($username,$password,$userRole)
   {
   
   if ($this->checkIfUserExists($username) == true)
        {
	//return true;
	}
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$userRole = $this->db->real_escape_string($userRole);
	$query = "select fname from PatientsDetails;";
	$results = $this->db->query($query);
	while($list=$results->fetch_assoc())
	{
	
	
	echo "Patient:".$list['fname'].PHP_EOL;
	
	}
	if ($this->db->errno > 0)
        {
		echo "DB error: ".$this->db->error.PHP_EOL;
		return;
        }
      }

          public function IndividualRecord($username,$password,$userRole)
   {
   
   if ($this->checkIfUserExists($username) == true)
        {
	//return true;
	}
	$username = $this->db->real_escape_string($username);
	$password = $this->db->real_escape_string($this->saltPassword($password));
	$userRole = $this->db->real_escape_string($userRole);
	$query = "select * from PatientsDetails;";
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

