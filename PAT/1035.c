# include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int origin[N], half_sort[N];
    int i, j;
    for (i=0; i < N; i++)
        scanf("%d", origin + i);
    for (i=0; i < N; i++)
        scanf("%d", half_sort + i);

    int length = 0;
    for (i=0; i < N-1 && half_sort[i] <= half_sort[i+1]; i++) ;
    for (length = i + 1; length < N; length++)
        if (origin[length] != half_sort[length])
            break;
    


    return 0;
}