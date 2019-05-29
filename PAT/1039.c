# include <stdio.h>
# include <string.h>

int main()
{
    char have[1001], want[1001];
    scanf("%s%s", have, want);
    int len_have = strlen(have), len_want = strlen(want);
    int isHave[len_have];
    int get = 0;

    //初始化isHave
    for (int i=0; i < len_have; i++)
        isHave[i] = 1;

    for (int i=0; i < len_want; i++) {
        for (int j=0; j < len_have; j++) {
            if (want[i] != have[j] || !isHave[j])
                continue;
            isHave[j] = 0;
            get++;
            break;
        }
        if (get == len_want)    break;
    }
    if (get < len_want)
        printf("No %d\n", len_want - get);
    else
        printf("Yes %d\n", len_have - len_want);

    return 0;
}