/*drop user `administrator`@`localhost`;*/
create user `administrator`@`localhost` identified by "admin";
grant all privileges on *.* to `administrator`@`localhost`;
flush privileges;