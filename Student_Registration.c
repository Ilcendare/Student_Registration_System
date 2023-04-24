/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Student registration program.     *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List_config.h"
#include "Linked_List.h"
#include "Student_Registration.h"


list_t *StudentList = NULL;


/* ========== Student registration program functions ========== */
void StudInfoDisplayFormat(lnode_t* node) {
    printf("\nName: %s %s\nID: %s\nDepartment: %s\nBirth date: %s\nAddress: %s\nPhone number:%s\nE-mail: %s\n",
           node->dataPtr->FirstName, node->dataPtr->LastName, node->dataPtr->ID, node->dataPtr->Department,
           node->dataPtr->BirthDate, node->dataPtr->Address, node->dataPtr->PhoneNumber, node->dataPtr->Email);
}


void Student_Registration_init(void) {
    StudentList = (list_t *) malloc(sizeof(list_t));
    Linked_List_Init(StudentList);
}


void Student_Registration_saveData(void) {
    FILE *StudentsFile;
    lnode_t *ptr = StudentList->first;
    int counter = 0;
    StudentsFile = fopen("Students_Data.dat","w");
    while(ptr != NULL) {
        fseek(StudentsFile,(long)(counter * sizeof(DATA)),SEEK_SET);
        fwrite(ptr->dataPtr, sizeof(DATA),1,StudentsFile);
        counter++;
        ptr = ptr->NextNode;
    }
    fclose(StudentsFile);
}



int Student_Registration_loadData(void) {
    FILE *StudentsFile;
    StudentsFile = fopen("Students_Data.dat","r");
    if(StudentsFile == NULL) return 0;
    DATA *DataLoaded;
    while(!feof(StudentsFile)) {
        DataLoaded = (DATA *) malloc(sizeof(DATA));
        int res = (int) fread(DataLoaded,sizeof(DATA),1,StudentsFile);
        if(res != 0) {
            Linked_List_AddNode(StudentList,DataLoaded);
        }
    }
    fclose(StudentsFile);
    return 1;
}



void Student_Registration_menu(void) {
    char select;
    _Bool QUIT = 0;
    int tries = 3;
    char password[PASSWORD_MAX_LENGTH];
    /* Password Lock System */
    printf("Please enter the password: ");
    while(tries--) {
        scanf("%s", password);
        if (strcmp(password, SYS_PASSWORD) != 0) {
            if (tries == 0) exit(0);
            printf("Wrong password, you have %d time/s left.\n>", tries);
        }
        else break;
    }

    printf("\n\n===============================================================\n");
    printf("###########          Student Registration System     ##########\n");
    printf("===============================================================\n");
    printf("#########   Please Choose from the following options   ########\n");
    printf("===============================================================\n\n");
    printf("\t(+)\ta) Register a new student\t\t(+)\n");
    printf("\t(+)\td) Delete an existing student\t\t(+)\n");
    printf("\t(+)\tl) List a student's information\t\t(+)\n");
    printf("\t(+)\tL) List all students information\t(+)\n");
    printf("\t(+)\te) Edit a student's information\t\t(+)\n");
    printf("\t(+)\tq) Quit program\t\t\t\t(+)\n");

    do {
        char Continue;
        printf("\nType Here: ");
        fflush(stdin);
        scanf("%c", &select);
        switch (select) {
            case 'a':
                do {
                    int result = Student_Registration_addStudent();
                    if(result) printf("The Account has added successfully.\n");
                    else printf("The process has aborted.\n");
                    printf("Do you want to add another account? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'd':
                do {
                    Student_Registration_deleteStudent();
                    printf("Do you want to delete another account? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'l':
                do {
                    Student_Registration_listStudentInfo();
                    printf("Do you want to list another account? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'L':
                Student_Registration_listAllStudents();
                break;
            case 'e':
                do {
                    Student_Registration_editStudentInfo();
                    printf("Do you want to edit another account? (y - yes, n - no)\n");
                    do {
                        printf(">");
                        fflush(stdin);
                        scanf("%c", &Continue);
                        if ((Continue != 'y') && (Continue != 'n')) {
                            printf("Please enter a valid answer.\n");
                        }
                    } while((Continue != 'y') && (Continue != 'n'));
                } while(Continue == 'y');
                break;
            case 'q':
                QUIT = 1;
                break;
            default:
                printf("Please enter one of the shown settings (a, d, l, L, e, or q lowercase)\n");
        }
        fflush(stdin);
    } while(!QUIT);
}



int Student_Registration_addStudent(void) {
    DATA *NewStudent;
    NewStudent = (DATA *) malloc(sizeof(DATA));
    printf("Please enter the first and last name:");
    scanf("%20s %20s", NewStudent->FirstName, NewStudent->LastName);
    fflush(stdin);
    printf("Please enter the birth date (dd/mm/yyyy):");
    fflush(stdin);
    scanf("%s", NewStudent->BirthDate);
    printf("Please enter the ID number:");
    fflush(stdin);
    /* This step is done to check if the ID number entered is already registered in the system or not */
    char id[15];
    int Abort = 0;
    lnode_t *ptr = StudentList->first;
    scanf("%s", id);
    while(ptr != NULL) {
        if((strcmp(ptr->dataPtr->ID, id)) == 0) {
            printf("You cannot enter an ID number that belongs to another student.\n");
            Abort = 1;
            break;
        }
        ptr = ptr->NextNode;
    }
    if(Abort == 1) {
        free(NewStudent);
        return 0;
    }
    /* End of checking step */
    strcpy(NewStudent->ID, id);
    printf("Please enter the address:");
    fflush(stdin);
    scanf("%s", NewStudent->Address);
    printf("Please enter the phone number: ");
    fflush(stdin);
    scanf("%s", NewStudent->PhoneNumber);
    printf("Please enter the E-mail: ");
    fflush(stdin);
    scanf("%s", NewStudent->Email);
    printf("Please enter the desired department: ");
    fflush(stdin);
    scanf("%s", NewStudent->Department);

    Linked_List_AddNode(StudentList, NewStudent);
    return 1;
}



void Student_Registration_deleteStudent(void) {
    char id[15];
    int result;
    printf("Please enter the ID number of the student:");
    fflush(stdin);
    scanf("%s",id);

    result = Linked_List_DeleteNode(StudentList,id);
    if(result)
        printf("The student account has deleted successfully.\n");
    else
        printf("The student is not included in the system.\n");
}



void Student_Registration_editStudentInfo(void) {
    char id[15];
    lnode_t *Student;
    printf("Please enter the ID number of the student:");
    fflush(stdin);
    scanf("%14s",id);

    Student = Linked_List_FindNode(StudentList, id);
    if (Student != NULL) {
        char firstName[21] = "0";
        char lastName[21] = "0";
        char birthDate[11] = "0";
        char address[31] = "0";
        char phoneNumber[12] = "0";
        char email[31] = "0";
        char department[31] = "0";

        printf("Enter the new student's information in the following order: first name, last name, birth date,"
               " address, e-mail, phone number, and department.\nIf one of the mentioned you don't want to alter,"
               "enter 0 instead.");
        scanf("%20s %20s %10s %30s %11s", firstName, lastName, birthDate, address, phoneNumber);
        if(strcmp(firstName, "0") != 0) {
            strcpy(Student->dataPtr->FirstName , firstName);
        }
        if(strcmp(lastName, "0") != 0) {
            strcpy(Student->dataPtr->LastName , lastName);
        }
        if(strcmp(address, "0") != 0) {
            strcpy(Student->dataPtr->Address , address);
        }
        if(strcmp(birthDate, "0") != 0) {
            strcpy(Student->dataPtr->BirthDate , birthDate);
        }
        if(strcmp(phoneNumber, "0") != 0) {
            strcpy(Student->dataPtr->PhoneNumber , phoneNumber);
        }
        if(strcmp(email, "0") != 0) {
            strcpy(Student->dataPtr->Email , email);
        }
        if(strcmp(department, "0") != 0) {
            strcpy(Student->dataPtr->Department , department);
        }
    }
    else printf("The student is not included in the system.\n");
}



void Student_Registration_listStudentInfo(void) {
    char id[15];
    lnode_t *Student;
    printf("Please enter the ID number of the student:");
    fflush(stdin);
    scanf("%14s",id);

    Student = Linked_List_FindNode(StudentList,id);
    if (Student != NULL) StudInfoDisplayFormat(Student);
    else printf("The student is not included in the system.\n");
}



void Student_Registration_listAllStudents(void) {
    Linked_List_ListNodes(StudentList, StudInfoDisplayFormat);
}


