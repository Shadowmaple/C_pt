#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct linkList
    {
        int number;
        struct linkList *next;
    };

    struct linkList *head, *tail, *pnew;
    int number;

    head = (struct linkList *)malloc (sizeof(struct linkList));
    head->next = NULL;
    tail = head;
    //初始时尾链即首链，尾链指针指向首链地址

    while(1) {
        scanf("%d", &number);
        if (number == -1)
            break;

        pnew = (struct linkList *)malloc (sizeof(struct linkList));
        pnew->number = number;
        pnew->next = NULL;

        //该链与上一链（尾链）进行链接，上一链的next指向该链地址
        tail->next = pnew;
        tail = pnew;
        //尾指针指向该链地址，该该链成为尾链
    }

    //输出链表中的数据域
    for (struct linkList *p=head->next; p != NULL; p = p->next) {
        printf("%d\n", p->number);
    }
    if (!(head->next))
        puts("No any number!\a");

    return 0;
}