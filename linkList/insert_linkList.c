#include <stdio.h>
#include <stdlib.h>

struct linkList
{
    int number;
    struct linkList *next;
};
typedef struct linkList NODE;

void show(NODE *head)
{   
    NODE *p = head->next;
    while (p != NULL) {
        printf("%d ", p->number);
        p = p->next;
    }
    putchar('\n');
}

int main()
{
    NODE *head, *tail, *new;
    int number;

    head = (NODE *)malloc (sizeof(NODE));
    head->next = NULL;
    tail = head;

    puts("输入一组原始数字：");
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
    //显示当前数据
    show(head);

    int position;
    puts("输入要插入的位置和数字(-1为停止)：");
    while (1) {
        scanf("%d", &position);
        if (position == -1)
            break;
        scanf("%d", &number);

        NODE *p = head;
        for (int i=0; i<=position && p != NULL; i++)
            p = p->next;
        if (p == NULL) {
            puts("该节点不存在");
            continue;
        }
        
        new = (NODE *) malloc (sizeof(NODE));
        new->next = p->next;
        new->number = number;
        p->next = new;

        //展示插入后的结果
        show(head);
    }

    return 0;
}