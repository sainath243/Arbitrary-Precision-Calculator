#include "apc.h"
#include <stdlib.h>

// Insert at head
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist*)malloc(sizeof(Dlist));
    if(!new_node) return FAILURE;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;

    if(*head != NULL)
        (*head)->prev = new_node;
    else
        *tail = new_node;

    *head = new_node;
    return SUCCESS;
}

// Insert at tail
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = (Dlist*)malloc(sizeof(Dlist));
    if(!new_node) return FAILURE;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = *tail;

    if(*tail != NULL)
        (*tail)->next = new_node;
    else
        *head = new_node;

    *tail = new_node;
    return SUCCESS;
}

// Delete entire list
int dl_delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    while(temp != NULL)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}
