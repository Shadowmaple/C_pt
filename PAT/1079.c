# include <stdio.h>
# include <string.h>

int check(char *n)
{
    int flag = 1, len = strlen(n);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (n[i] != n[j]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("%s is a palindromic number.\n", n);
    return flag;
}

void reserve(char *a, char *b)
{
    int len = strlen(a);
    for (int i = 0, j = len - 1; i < len; i++, j--)
        b[j] = a[i];
    b[len] = '\0';
}

void sum(char *n)
{
    char rev[1001], num[1001];
    reserve(n, rev);
    int i, index = 999, flag = 0;
    for (i = strlen(n) - 1; i >= 0; i--, index--) {
        int x = n[i] - '0' + (rev[i] - '0') + flag;
        num[index] = x % 10 + '0';
        flag = x / 10;
    }
    if (flag) num[index--] = flag + '0';
    num[1000] = '\0';
    strcpy(num, num + index + 1);

    printf("%s + %s = %s\n", n, rev, num);
    strcpy(n, num);
}

int main()
{
    char n[1001], num[1001];
    scanf("%s", n);

    if (check(n))
        return 0;

    for (int i = 0; i < 10; i++) {
        sum(n);
        if (check(n)) return 0;
    }
    puts("Not found in 10 iterations.");
    
    return 0;
}