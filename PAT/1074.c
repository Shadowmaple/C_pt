# include <stdio.h>
# include <string.h>

int main()
{
    char table[21], a[21], b[21], sum[22];;
    scanf("%s%s%s", table, a, b);

    int len = strlen(table);
    int len_a = strlen(a), len_b = strlen(b);
    int flag = 0;
    
    // 使用memset会出错
    for (int i = 0; i < 21; i++)
        sum[i] = '0';
    sum[21] = '\0';
    
    int k = len - 1, index = 20;
    for (int i = len_a - 1, j = len_b - 1; k >= 0; i--, j--, k--) {
        int x;
        if (i >= 0 && j >= 0)
            x = a[i] - '0' + (b[j] - '0') + flag;
        else if (i >= 0)
            x = a[i] - '0' + flag;
        else
            x = b[j] - '0' + flag;

        int y = (table[k] != '0') ? table[k] - '0' : 10;
        flag = x / y;        
        sum[index--] = x % y + '0';
    }
    // 最后的进位
    sum[index] = flag + '0';

    int i = 0;
    while (i < 21 && sum[i++] == '0') ;

    strcpy(sum, sum + i - 1);
    printf("%s\n", sum);

    return 0;
}