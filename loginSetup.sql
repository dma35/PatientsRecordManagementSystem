use PatientReg;
drop table if exists login;
create table login
(
  login INT(11) primary key Auto_Increment,
  Password varchar(255),
  username varchar(32),
  userRole ENUM('HCProvider','Patient'),
  dispalyName varchar(255)
);