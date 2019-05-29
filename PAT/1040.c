# include <stdio.h>
# include <string.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    long num_p, num_pa, total;
    num_p = num_pa = total = 0;

    int length = strlen(str);
    for (int i=0; i < length; i++) {
        if (str[i] == 'P')
            num_p++;
        else if (str[i] == 'A')
            num_pa += num_p;
        else total += num_pa;
    }

    printf("%ld\n", total % 1000000007);

    return 0;
}