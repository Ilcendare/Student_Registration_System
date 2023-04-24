/***************************************************/
/*  Author      : Mahmoud Sayed                     *
 *  Date        : 23 April 2023                     *
 *  Description : Linked List's source file.        *
 *  Email       : Thrtr619@gmail.com                *
 *                                                  *
 ***************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linked_List_config.h"
#include "Linked_List.h"


/* ========== Functions declarations ========== */
void Linked_List_Init(list_t *List) {
    List->first = NULL;
    List->last = NULL;
}


void Linked_List_AddNode(list_t *List, DATA *NewData) {
    lnode_t *ptr, *last;
    if(List->first == NULL) {
        List->first = (lnode_t *) malloc(sizeof(lnode_t));
        List->first->dataPtr = NewData;
        List->first->NextNode = NULL;
        List->last = NULL;
    } else {
        ptr = List->first->NextNode;
        last = List->first;
        while(ptr != NULL) {
            last = ptr;
            ptr = ptr->NextNode;
        }
        ptr = (lnode_t *) malloc(sizeof(lnode_t));
        last->NextNode = ptr;
        ptr->NextNode = NULL;
        ptr->dataPtr = NewData;
        List->last = ptr;
    }
}


int Linked_List_DeleteNode(list_t *List, char id[]) {
    lnode_t *ptr, *deleteNode, *last;
    DATA *deleteAccount;
    int found = 0;
    ptr = List->first;
    if(ptr == NULL) return 0;
    else {
        if (ptr->NextNode == NULL) {     // In case of single node list
            if (strcmp(ptr->dataPtr->ID, id) == 0) {
                deleteAccount = ptr->dataPtr;
                deleteNode = ptr;
                List->first = ptr->NextNode;
                free(deleteAccount);
                free(deleteNode);
                ptr = NULL;
                found = 1;
            } else {
                found = 0;
            }
        } else {                        // In case of multiple nodes list
            last = ptr;
            while (ptr != NULL) {
                if (strcmp(ptr->dataPtr->ID, id) == 0) {
                    deleteAccount = ptr->dataPtr;
                    deleteNode = ptr;
                    if (List->first == ptr) List->first = ptr->NextNode;
                    if (List->last == ptr) List->last = last;
                    last->NextNode = ptr->NextNode;
                    free(deleteAccount);
                    free(deleteNode);
                    ptr = NULL;
                    found = 1;
                } else {
                    found = 0;
                    last = ptr;
                    ptr = ptr->NextNode;
                }
            }
        }
    }
    return found;
}


void* Linked_List_FindNode(list_t *List, char id[]) {
    lnode_t *ptr;
    ptr = List->first;
    if(List->first == NULL) return NULL;
    else {
        if (ptr->NextNode == NULL) {     // In case of single node list
            if (strcmp(ptr->dataPtr->ID, id) == 0) {
                return ptr;
            } else {
                return NULL;
            }
        } else {                        // In case of multiple nodes list
            while (ptr != NULL) {
                if (strcmp(ptr->dataPtr->FirstName, id) == 0) {
                    return ptr;
                } else {
                    ptr = ptr->NextNode;
                }
            }
        }
    }
    return NULL;
}


void Linked_List_ListNodes(list_t *List, void (*DisplayFormatFunction) (lnode_t*)) {
    lnode_t *ptr;
    ptr = List->first;
    while(ptr != NULL) {
        DisplayFormatFunction(ptr);
        ptr = ptr->NextNode;
    }
}