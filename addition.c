/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int carry = 0;

    while(t1 != NULL || t2 != NULL)
    {
        int val1 = 0;
        int val2 = 0;

        if(t1 != NULL)
            val1 = t1->data;

        if(t2 != NULL)
            val2 = t2->data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;

        dl_insert_first(headR, tailR, digit);

        carry = sum / 10;

        if(t1 != NULL)
            t1 = t1->prev;
        if(t2 != NULL)
            t2 = t2->prev;
    }

    if(carry > 0)
    {
        dl_insert_first(headR, tailR, carry);
    }
}
