Drop database if exists patient_record_system;
create database patient_record_system;
use patient_record_system;
/*drop table if exists `PatientsDetails`;*/
create table `PatientsDetails` (
  patientID int(10) primary key not null auto_increment,
  fname varchar(255),
  lname varchar(255),
  address varchar(255),
  phone varchar(255),
  notes varchar(255)
  
 );

/*insert into `PatientsDetails`(
  fname,
  lname,
  address,
  phone
  )
values(
  "DJ",
  "Kehoe",
  "union",
  "7324944254"
  );

insert into `PatientsDetails`(
  fname,
  lname,
  address,
  phone)
values(
  "Aqib",
  "Mian",
  "newark",
  "7325642314"
),
(
  "Bo",
  "Thompson",
  "montclair",
  "7325648762"
);*/
