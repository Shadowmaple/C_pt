# include <stdio.h>
# include <string.h>

int main()
{
    int d, n;
    scanf("%d %d", &d, &n);

    char result[1000];
    result[0] = d + '0';
    result[1] = '1';
    result[2] = '\0';
  
    for (int j = 2; j < n; j++) {
        int count = 1;
        char pre = result[0];
        char str[1000];
        int index = 0;
        int i = 1;
        do {
            if (result[i] == pre) {
                count++;
                continue;
            }
            str[index++] = pre;
            str[index++] = count + '0';
            pre = result[i];
            count = 1;
        } while (i++ < strlen(result));

        str[index] = '\0';
        strcpy(result, str);
        // printf("%s\n", result);
    }
    printf("%s\n", result);
    return 0;
}