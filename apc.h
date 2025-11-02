#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE 1

typedef struct dlist {
    int data;
    struct dlist *prev;
    struct dlist *next;
} Dlist;

// Linked list functions
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_delete_list(Dlist **head, Dlist **tail);

// String conversion & validation
void string_to_dlist(const char *numStr, Dlist **head, Dlist **tail);
int validate(const char *numStr);

// Arithmetic operations
void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
              Dlist **headR, Dlist **tailR);
void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                 Dlist **headR, Dlist **tailR);
void multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
                    Dlist **headR, Dlist **tailR);
void division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,
              Dlist **headR, Dlist **tailR);

// Utility functions
int compare_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);

#endif
