# include <stdio.h>

struct link
{
    int data;
    struct link *next;
    int num;
};

struct data
{
    int address;
    int data;
    int next_address;
};

int main()
{
    int N, K, address;
    //char address[6];
    scanf("%d%d%d", &address, &N, &K);
    struct link *head, *tail, *new;
    struct data number[N];

    head = (struct link *)malloc (sizeof(struct link));
    head->next = address;
    tail = head;

    for (int i=0; i < N; i++) {
        scanf("%d%d%d", &number[i].address, &number[i].data, &number[i].next_address);
    }

    for (int j=0; j < N; j++) {
        for (int i=0; i < N; i++) {
            if (tail->next != number[i].address)
                continue;

            new = number[i].address;
            new->data = number[i].data;
            if (number[i].next_address == -1)
                new->next = NULL;
            new->next = number[i].next_address;

            tail->next = number[i].address;
            tail = new;
        }
    }

    


    return 0;
}