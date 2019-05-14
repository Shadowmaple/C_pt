# include <stdio.h>

struct linkList
{
    int address;
    int data;
    int next;
};

int main()
{
    int N, K, address;
    scanf("%d%d%d", &address, &N, &K);
    struct linkList link_x[N];
    struct linkList *link[N];

    for (int i=0; i < N; i++) {
        link[i] = link_x + i;
        scanf("%d%d%d", &link[i]->address, &link[i]->data, &link[i]->next);
    }

    //链接链表，即对数组排序
    for (int i=0; i < N-1; i++) {
        for (int j=i; j < N; j++) {
            if (link[j]->address != (i ? link[i-1]->next : address))
                continue;
            //swap(link[i], link[j]);
            struct linkList *a = link[i];
            link[i] = link[j];
            link[j] = a;
            break;
        }
        //去掉后面不属于链表的节点
        if(link[i]->next == -1)
            N = i + 1;
        //printf("---%05d %d %05d\n", link[i]->address, link[i]->data, link[i]->next);
    }
    //printf("---%05d %d -1\n", link[N-1]->address, link[N-1]->data);

    //反转链表，对数组交换顺序
    for (int i=0; i < N / K; i++) {
        for (int j = i*K, m = j+K-1; j < i*K + K/2; j++, m--) {
            //swap(link[j], link[m]);
            struct linkList *a = link[j];
            link[j] = link[m];
            link[m] = a;
        }
    }

    //putchar('\n');
    for (int i=0; i < N-1; i++) {
        printf("%05d %d %05d\n", link[i]->address, link[i]->data, link[i+1]->address);
        //注意最后输出的下一节点地址不是用本节点的next值输出
    }
    printf("%05d %d -1\n", link[N-1]->address, link[N-1]->data);
    return 0;
}