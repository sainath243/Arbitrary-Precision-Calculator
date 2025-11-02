/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "apc.h"

// Text color macros
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define ORANGE  "\033[1;33m"

// ================== Menu ==================
void display_menu()
{
    printf("╔════════════════════════════════╗\n");
    printf("║\033[38;5;16m\033[48;5;208m      BIG NUMBER CALCULATOR     \033[0m║\n");
    printf("╠════════════════════════════════╣\n");
    printf("║ 1. \033[1;32mAddition\033[0m       (+)          ║\n");
    printf("║ 2. \033[1;33mSubtraction\033[0m    (-)          ║\n");
    printf("║ 3. \033[1;34mMultiplication\033[0m (*)          ║\n");
    printf("║ 4. \033[1;35mDivision\033[0m       (/)          ║\n");
    printf("║ 5. " RED "Exit" RESET "                        ║\n");
    printf("╚════════════════════════════════╝\n");
    printf(YELLOW "Enter your choice: " RESET);
}

// ================== Result Box ==================
void print_result_box(Dlist *headR)
{
    if (headR == NULL)
    {
        printf(RED "Result is empty (operation failed)\n" RESET);
        return;
    }

    int count = 0;
    Dlist *temp = headR;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    char label[] = "Result:";
    int label_len = 7;
    int padding = 4;
    int width = label_len + count + padding;

    printf("╔");
    for (int i = 0; i < width; i++) printf("═");
    printf("╗\n");

    printf("║" ORANGE "%s" RESET " ", label);

    int spaces = width - label_len - 1 - count;
    int left_spaces = spaces / 2;
    int right_spaces = spaces - left_spaces;

    for (int i = 0; i < left_spaces; i++) printf(" ");
    temp = headR;
    while (temp != NULL)
    {
        printf(GREEN "%d" RESET, temp->data);
        temp = temp->next;
    }
    for (int i = 0; i < right_spaces; i++) printf(" ");
    printf("║\n");

    printf("╚");
    for (int i = 0; i < width; i++) printf("═");
    printf("╝\n\n");
}

// ================== Main Function ==================
int main()
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    char choice;
    char num1[100], num2[100];

    while (1)
    {
        display_menu();
        scanf(" %c", &choice);

        if (choice == '5') break;

        printf(BLUE "Enter first number: " RESET);
        scanf("%s", num1);
        if (validate(num1) == FAILURE)
        {
            printf(RED "Invalid input! Digits only.\n" RESET);
            continue;
        }

        printf(BLUE "Enter second number: " RESET); 
        scanf("%s", num2);
        if (validate(num2) == FAILURE)
        {
            printf(RED "Invalid input! Digits only.\n" RESET);
            continue;
        }

        string_to_dlist(num1, &head1, &tail1);
        string_to_dlist(num2, &head2, &tail2);
        dl_delete_list(&headR, &tailR);

        switch (choice)
        {
            case '1':
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;

            case '2':
                if (compare_lists(head1, tail1, head2, tail2) < 0)
                {
                    printf(RED "Error: Negative result not supported\n" RESET);
                    dl_delete_list(&head1, &tail1);
                    dl_delete_list(&head2, &tail2);
                    continue;
                }
                subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;

            case '3':
                multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;

            case '4':
                if (head2 != NULL && head2->data == 0 && head2->next == NULL)
                {
                    printf(RED "Error: Division by zero\n" RESET);
                    dl_delete_list(&head1, &tail1);
                    dl_delete_list(&head2, &tail2);
                    continue;
                }
                division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
                break;

            default:
                printf(RED "Invalid choice!\n" RESET);
                dl_delete_list(&head1, &tail1);
                dl_delete_list(&head2, &tail2);
                continue;
        }

        print_result_box(headR);
        dl_delete_list(&head1, &tail1);
        dl_delete_list(&head2, &tail2);
    }

    dl_delete_list(&headR, &tailR);
    printf(CYAN "Thank you for using Big Number Calculator!\n" RESET);
    return 0;
}