#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int number;
    struct linkList *next;
};
typedef struct linkList NODE;

void display(NODE *head)
{
    NODE *p = head->next;
    while (p != NULL) {
        printf("%d ", p->number);
        p = p->next;
    }
    putchar('\n');
}

void delete(NODE *head)
{
    int position;

    puts("输入要删除的节点（从1开始）：");
    while (1) {
        scanf("%d", &position);
        if (position < 1)
            break;
        
        NODE *p = head;
        for (int i=0; i < position-1 && p != NULL; i++)
            p = p->next;
        
            
    }
}

void insert(NODE *head, NODE *tail)
{
    NODE *new;
    int number, position;

    puts("输入插入的位置和数字（-1退出）：");
    while (1) {
        scanf("%d", &position);
        if (position == -1)
            break;
        scanf("%d", &number);

        NODE *p = head;
        for (int i=0; i < position && p != NULL; i++)
            p = p->next;

        if (!p) {
            puts("该节点不存在！");
            continue;
        }
        
        new = (NODE *) malloc(sizeof(NODE));
        new->number = number;
        new->next = p->next;
        p->next = new;
        
        display(head);
    }
}

void create(NODE *head, NODE *tail, NODE *new)
{
    int *number;

    head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;
    tail = head;

    puts("输入数据：");
    while(1) {
        scanf("%d", number);
        if (*number == -1)
            break;
        
        new = (NODE *) malloc(sizeof(NODE));
        new->next = NULL;
        new->number = *number;

        tail->next = new;
        tail = new;
    }
    display(head);
}

int main()
{
    NODE *head, *tail, *new;
    int option;

    create(head, tail);

    puts("选项：退出--0，插入--1，删除--2，销毁--3");
    while (1) {
        scanf("%d", &option);
        switch (option) {
            case 0: break;
            case 1: insert(head, tail, new); break;
            case 2: delete(head); break;
            case 3: free(head); break;
            default: continue;
        }
    }

    return 0;
}
