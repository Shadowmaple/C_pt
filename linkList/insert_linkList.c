#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int number;
    struct linkList *next;
};
typedef struct linkList NODE;

int main()
{
    NODE *head, *tail, *new;
    int number;

    head = (NODE *)malloc (sizeof(NODE));
    head->next = NULL;
    tail = head;

    while(1) {
        scanf("%d", &number);
        if (number == -1)
            break;

        new = (NODE *) malloc (sizeof(NODE));
        new->next = NULL;
        new->number = number;

        tail->next = new;
        tail = new;
    }

    

    return 0;
}