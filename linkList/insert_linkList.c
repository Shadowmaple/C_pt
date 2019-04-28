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

    puts("输入一组原始数字：")
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

    int position;
    puts("输入要插入的位置和数字：")
    while (scanf("%d", &position) != -1) {    
        scanf("%d", &number);

        NODE *p;
        for (int i=0; i<=position && p != NULL; i++)
            p = p->next;
        if (p == NULL)
            puts("该节点不存在")
        

    }



    return 0;
}