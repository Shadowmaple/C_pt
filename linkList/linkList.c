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
    free(p);
}

void free_linkList(NODE *head)
{
    NODE *p = head, *p_free;
    while (p != NULL) {
        p_free = p;
        p = p->next;
        free(p_free);
    }
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
        for (int i=0; i < position-1 && p->next != NULL; i++)
            p = p->next;

        if (p->next == NULL) {
            puts("该节点不存在！");
            continue;
        }
        
        NODE *p_free = p->next;
        p->next = p_free->next;
        //释放内存
        free(p_free);
        
        display(head);
    }
}

void insert(NODE *head)
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

        new = (NODE *) malloc (sizeof(NODE));
        new->number = number;
        new->next = p->next;
        p->next = new;
        
        display(head);
    }
}

void create(NODE *head, NODE *tail)
{
    NODE *new;
    int number;

    //若是在此处为head分配内存则后续的运行会报错
    //head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;
    tail = head;

    puts("输入数据：");
    while(1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        
        new = (NODE *) malloc(sizeof(NODE));
        new->next = NULL;
        new->number = number;

        tail->next = new;
        tail = new;
    }
    display(head);
}

int main()
{
    NODE *head, *tail;
    int option;
    
    head = (NODE *) malloc(sizeof(NODE));
    create(head, tail);

    while (1) {
        puts("选项：退出--0，插入--1，删除--2，销毁--3");
        scanf("%d", &option);
        switch (option) {
            case 0: return 0;
            case 1: insert(head); break;
            case 2: delete(head); break;
            case 3: free_linkList(head); return 0;
            default: continue;
        }
    }

    return 0;
}
