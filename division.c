/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "apc.h"


void division(Dlist **head1, Dlist **tail1,
              Dlist **head2, Dlist **tail2,
              Dlist **headR, Dlist **tailR)
{
    Dlist *dividend = *head1;
    Dlist *divisorHead = *head2;
    Dlist *divisorTail = *tail2;

    *headR = *tailR = NULL;

    if (compare_lists(*head1, *tail1, *head2, *tail2) < 0)
    {
        dl_insert_last(headR, tailR, 0);
        return;
    }

    Dlist *tempDividendHead = NULL;
    Dlist *tempDividendTail = NULL;

    while (dividend != NULL)
    {
        // Bring down next digit
        dl_insert_last(&tempDividendHead, &tempDividendTail, dividend->data);

        // Remove leading zeros
        while (tempDividendHead != NULL && tempDividendHead->data == 0 && tempDividendHead->next != NULL)
        {
            Dlist *tmp = tempDividendHead;
            tempDividendHead = tempDividendHead->next;
            tempDividendHead->prev = NULL;
            free(tmp);
        }

        int count = 0;

        // Repeated subtraction
        while (compare_lists(tempDividendHead, tempDividendTail, divisorHead, divisorTail) >= 0)
        {
            Dlist *tempRHead = NULL, *tempRTail = NULL;
            subtraction(&tempDividendHead, &tempDividendTail,
                        &divisorHead, &divisorTail,
                        &tempRHead, &tempRTail);

            dl_delete_list(&tempDividendHead, &tempDividendTail);
            tempDividendHead = tempRHead;
            tempDividendTail = tempRTail;

            count++;
        }

        // Append quotient digit
        dl_insert_last(headR, tailR, count);
        dividend = dividend->next;
    }

    // Remove leading zeros
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *tmp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(tmp);
    }

    dl_delete_list(&tempDividendHead, &tempDividendTail);
}
