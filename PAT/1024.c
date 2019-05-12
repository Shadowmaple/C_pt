#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//指数为正数，即该数大于0的情况
void positive(char *string_num, int exponent, int index_E)
{

}

//指数为负数，即该数小于0的情况
void negative(char *string_num, int exponent, int index_E)
{
    printf("0.");
    for (int i=1; i < exponent; i++) {
        putchar('0');
    }
    for (int i=1; i < index_E; i++) {
        if (string_num[i] == '.')
            continue;
        printf("%c", string_num[i]);
    }
}

int main()
{
    char string_num[9999];
    int exponent = 0, index_E = 0;  //指数大小和字符E的下标
    int sign;

    scanf("%s", string_num);

    //先输出负号，正号不用输出
    if (string_num[0] == '-')
        putchar('-');

    for (int i=1; i < strlen(string_num); i++) {
        if (string_num[i] != 'E')
            continue;
        index_E = i;
        sign = string_num[++i];     //存储指数的正负号
        while (string_num[i] != '\0') {
            exponent = exponent * 10 + (string_num[i] - '0');
            i++;
        }
        break;
    }

    //指数为0的情况
    if (!exponent) {
        


        return 0;
    }

    if (sign == '+')
        positive(string_num, exponent, index_E);
    else
        negative(string_num, exponent, index_E);

    putchar('\n');
    return 0;
}