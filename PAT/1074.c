# include <stdio.h>
# include <string.h>

int main()
{
    char table[21], a[21], b[21], sum[21];;
    scanf("%s", table);
    scanf("%s%s", a, b);

    int len = strlen(table);
    int len_a = strlen(a), len_b = strlen(b);
    
    int flag = 0;
    // memset(sum, '0', sizeof(char));
    for (int i = 0; i < 20; i++)
        sum[i] = '0';
    sum[20] = '\0';
    
    int k = len - 1, index = 19;
    for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0; i--, j--, k--) {
        int x;
        if (i >= 0 && j >= 0)
            x = a[i] - '0' + (b[j] - '0') + flag;
        else if (i >= 0)
            x = a[i] - '0' + flag;
        else if (j >= 0)
            x = b[j] - '0' + flag;

        int y = (table[k] - '0' != 0) ? table[k] - '0' : 10;
        flag = x / y;        
        sum[index--] = x % y + '0';
    }
    int i = 0;
    while (sum[i++] == '0') ;

    strcpy(sum, sum + i - 1);

    printf("%s\n", sum);

    return 0;
}