/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Linked list's configurations.     *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_CONFIG_H
#define STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_CONFIG_H


/* =========== Define the data structure for each node =========== */
typedef struct Student {
    char ID[15];
    char FirstName[21];
    char LastName[21];
    char BirthDate[11];
    char Address[31];
    char PhoneNumber[13];
    char Email[31];
    char Department[31];
} student_t;


/* =========== Configure important macros for the Linked List's functions =========== */
#define DATA        student_t           // The list node's data it holds


#endif //STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_CONFIG_H
