/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Linked List's header file.        *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#ifndef STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_H
#define STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_H


/* =========== Defining the structure of lists and nodes =========== */
typedef struct ListNode {
    DATA *dataPtr;
    struct ListNode *NextNode;
} lnode_t;

typedef struct List {
    lnode_t *first;
    lnode_t *last;
}list_t;


/* =========== Function prototypes =========== */
void Linked_List_Init(list_t *List);
void Linked_List_AddNode(list_t *List, DATA *NewData);
int Linked_List_DeleteNode(list_t *List, char id[]);
void* Linked_List_FindNode(list_t *List, char id[]);
void Linked_List_ListNodes(list_t *List, void (*DisplayFormatFunction) (lnode_t*));


#endif //STUDENT_REGISTRATION_SYSTEM_LINKED_LIST_H
