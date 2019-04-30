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

    head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;
    tail = head;

    puts("输入原数据：");
    while (1) {
        scanf("%d", &number);
        if (number == -1)
            break;
        
        new = (NODE *) malloc(sizeof(NODE));
        new->next = NULL;
        new->number = number;

        tail->next = new;
        tail = new;
    }
    show(head);

    int p_index;
    puts("输入要删除的节点(从1开始)：");
    while(head->next != NULL) {
        scanf("%d", &p_index);
        if (p_index == -1)
            break;
        if (p_index == 0) {
            show(head);
            continue;
        }

        NODE *p = head;
        for (int i=0; i < p_index-1 && p != NULL; i++) {
            p = p->next;
        }
        if (p->next == NULL) {
            puts("该节点不存在！");
            continue;
        }
        
        NODE *p_free = p->next;
        p->next = p_free->next;
        //释放内存
        free(p_free);

        show(head);
    }
    return 0;
}
