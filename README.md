# PatientsRecordManagementSystem
This project was assigned by my Database Administration professor (Professor DJ Kehoed). It's serves as a backend database for the web frontend. It is a mini project which has basic funtionalities that provies an interecation medium for the administrator and the health care providers who manage the information of patients.It also allows the patients to view thier own records.

Admin.sql logs in as the administrator and has all root privileges except for grant.

AddUser.php registers new health care provider and deletes user.

hcp.sql logs you in as general health care provider and has only select and update privileges.

BrowseList.php allows individual health care provider login.

IndividualRecord.php allows health care provider to view patients individual record.

AddNotes.php allows health care provider to add notes to  patients individual record.

PatientView.php allows patients to view their own record usind thier user_id and f.name.
