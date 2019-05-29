# include <stdio.h>
# include <string.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    int num_pa, num_pat, total;
    num_pa = num_pat = total = 0;

    int length = strlen(str);
    for (int i=0; i < length; i++) {
        if (str[i] != 'P')
            continue;
        for (int j=i+1; j < length; j++) {
            if (str[j] != 'T')
                continue;
            for (int k=i+1; k < j; k++) {
                if (str[k] == 'A')
                    total++;
            }
        }
    }
    printf("%d\n", total % 1000000007);

    return 0;
}