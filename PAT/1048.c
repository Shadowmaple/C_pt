# include <stdio.h>
# include <string.h>

int main()
{
    char a[101], b[101];
    char n[] = "0123456789JQK";
    scanf("%s %s", a, b);
    
    int len_a = strlen(a), len_b = strlen(b);
    int len_max = len_a >= len_b ? len_a : len_b;
    char result[len_max + 1];

    if (len_a < len_b) {
        char x[len_b - len_a];
        memset(x, '0', len_b - len_a);
        x[len_b - len_a] = '\0';
        strcpy(a, strcat(x, a));
    } else if (len_a > len_b) {
        char x[len_a - len_b + 1];
        memset(x, '0', len_a - len_b);
        x[len_a - len_b] = '\0';
        strcpy(b, strcat(x, b));
    }

    for (int i = len_max-1, j = 1; i >= 0; i--, j++) {
        int num;
        // 偶数位
        if (j % 2 == 0) {
            num = b[i] - '0' - (a[i] - '0');
            num = num < 0 ? num + 10 : num;
        } else {
            // 奇数位
            num = (b[i] - '0' + (a[i] - '0')) % 13;
        }
        result[i] = n[num];
    }
    result[len_max] = '\0';
    printf("%s\n", result);

    return 0;
}