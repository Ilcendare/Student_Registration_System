/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Student registration program.     *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef STUDENT_REGISTRATION_SYSTEM_STUDENT_REGISTRATION_H
#define STUDENT_REGISTRATION_SYSTEM_STUDENT_REGISTRATION_H


/* =========== The following macros can be configured =========== */
#define SYS_PASSWORD            "studReg00"     // You can type your desired password here
#define PASSWORD_MAX_LENGTH     50              // The password maximum length


/* =========== Function prototypes =========== */
void Student_Registration_init(void);
void Student_Registration_saveData(void);
int Student_Registration_loadData(void);
void Student_Registration_menu(void);
int Student_Registration_addStudent(void);
void Student_Registration_deleteStudent(void);
void Student_Registration_editStudentInfo(void);
void Student_Registration_listStudentInfo(void);
void Student_Registration_listAllStudents(void);



#endif //STUDENT_REGISTRATION_SYSTEM_STUDENT_REGISTRATION_H
