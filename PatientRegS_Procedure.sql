drop procedure if exists addPatient;
DELIMITER //
create procedure `addPatient`(
	IN patientID int(10),
	IN fname varchar(255),
	IN lname varchar(255),
	IN phone varchar(255),
	IN address varchar(255),
	IN notes varchar(255))
	
BEGIN
    insert into PatientsDetails (
	PatientsDetails.patientID,
	PatientsDetails.fname,
	PatientsDetails.lname,
	PatientsDetails.phone,
	PatientsDetails.address,
	PatientsDetails.notes)
     values(
	patientID,
	fname,
	lname,
	phone,
	address,
	notes);


END//