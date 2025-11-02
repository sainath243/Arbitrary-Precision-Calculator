/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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
		//1.insert zeros to R1
		//loop(till t1 reaches NULL)
		//2.multiply t1->data & t2->data & add carry
		//3.first time ->store to R2
		//else store to r1
		//4.traverse the t1
		//5.check for addition(r1 is NULL)
		//-add(R1,R2,R3)
		//-Delete-list(R1)
		//-Delete-list(R2)
		//-Assign headR2 =headR3
		//-Assign hR3=NULL
		//6.Traverse the t2
		//7.re assign the t1
void multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *t2 = *tail2;
    int zeros = 0; // To track position (like adding zeros)

    // Initialize result list as NULL
    *headR = NULL;
    *tailR = NULL;

    while(t2 != NULL)
    {
        Dlist *t1 = *tail1;
        int carry = 0;
        Dlist *tempResultHead = NULL;
        Dlist *tempResultTail = NULL;

        // Add zeros at the end for current position
        for(int i = 0; i < zeros; i++)
            dl_insert_last(&tempResultHead, &tempResultTail, 0);

        // Multiply t2->data with every digit in t1
        while(t1 != NULL)
        {
            int prod = t1->data * t2->data + carry;
            int digit = prod % 10;
            carry = prod / 10;

            dl_insert_first(&tempResultHead, &tempResultTail, digit);

            t1 = t1->prev;
        }

        if(carry > 0)
            dl_insert_first(&tempResultHead, &tempResultTail, carry);

        // Add tempResult to main result
        if(*headR == NULL)
        {
            *headR = tempResultHead;
            *tailR = tempResultTail;
        }
        else
        {
            Dlist *sumHead = NULL;
            Dlist *sumTail = NULL;
            addition(headR, tailR, &tempResultHead, &tempResultTail, &sumHead, &sumTail);

            // Delete old lists
            // (Assume you have a function dl_delete_list)
            dl_delete_list(headR, tailR);
            dl_delete_list(&tempResultHead, &tempResultTail);

            *headR = sumHead;
            *tailR = sumTail;
        }

        zeros++;       // Next digit of t2 is shifted one place
        t2 = t2->prev; // Move to next higher digit
    }
}
