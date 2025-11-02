/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "apc.h"

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int borrow = 0;

    while(t1 != NULL || t2 != NULL)
    {
        int val1 = 0;
        int val2 = 0;

        if(t1 != NULL)
            val1 = t1->data;

        if(t2 != NULL)
            val2 = t2->data;

        // Apply borrow
        val1 = val1 - borrow;

        int sub;
        if(val1 < val2)
        {
            sub = val1 + 10 - val2;
            borrow = 1; // borrow for next digit
        }
        else
        {
            sub = val1 - val2;
            borrow = 0;
        }

        dl_insert_first(headR, tailR, sub);

        if(t1 != NULL)
            t1 = t1->prev;
        if(t2 != NULL)
            t2 = t2->prev;
    }

    // Remove leading zeros if any
    while(*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }
}



