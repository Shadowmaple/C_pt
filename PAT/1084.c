# include <stdio.h>
# include <string.h>

int main()
{
    int d, n;
    scanf("%d %d", &d, &n);

    char result[100000], str[100000];
    // 最后一个测试点很大
    result[0] = d + '0';
    result[1] = '\0';
  
    for (int j = 1; j < n; j++) {
        char pre = result[0];
        int count = 1, index = 0, i = 1;
        int len = strlen(result);
        do {
            if (result[i] == pre) {
                count++;
                continue;
            }
            str[index++] = pre;
            str[index++] = count + '0';
            pre = result[i];
            count = 1;
        } while (i++ < len);
        // 这里不能用i++ < strlen(result)，会超时

        str[index] = '\0';
        strcpy(result, str);
    }
    printf("%s\n", result);
    return 0;
}