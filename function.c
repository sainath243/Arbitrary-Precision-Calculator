#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "apc.h"

// Convert string to doubly linked list
void string_to_dlist(const char *numStr, Dlist **head, Dlist **tail)
{
    for (int i = 0; numStr[i] != '\0'; i++)
    {
        int digit = numStr[i] - '0';
        dl_insert_last(head, tail, digit);
    }
}

// Validate number string
int validate(const char *ar)
{
    int i = 0;
    if(ar[i] == '+' || ar[i] == '-')
        i++;
    if(ar[i] == '\0')
        return FAILURE;

    for(; ar[i] != '\0'; i++)
    {
        if(!isdigit((unsigned char)ar[i]))
            return FAILURE;
    }
    return SUCCESS;
}
