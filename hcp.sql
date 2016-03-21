drop user `hcp`@`localhost`;
create user `hcp`@`localhost` identified by "hcp";
grant select on PatientsDetails to `hcp`@`localhost`;
grant insert on PatientsDetails to `hcp`@`localhost`;
flush privileges;