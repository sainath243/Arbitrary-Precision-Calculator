#include "apc.h"
#include <stdlib.h>

int compare_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    // Compare lengths first
    int len1 = 0, len2 = 0;
    Dlist *temp = head1;
    while(temp != NULL) { len1++; temp = temp->next; }
    temp = head2;
    while(temp != NULL) { len2++; temp = temp->next; }

    if(len1 > len2) return 1;
    if(len1 < len2) return -1;

    // Lengths equal, compare digit by digit
    Dlist *p1 = head1;
    Dlist *p2 = head2;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data > p2->data) return 1;
        if(p1->data < p2->data) return -1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 0; // equal
}