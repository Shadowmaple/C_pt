#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//指数为正数，即该数大于0的情况
void positive(char *string_num, int exponent, int index_E, int len_after_point)
{
    if (len_after_point <= exponent) {
        printf("%c", string_num[1]);
        for (int i=3; i < index_E; i++) {
            printf("%c", string_num[i]);
        }
        exponent -= len_after_point;
        for (int i=0; i < exponent; i++)
            putchar('0');
    } else {
        printf("%c", string_num[1]);
        int i;
        for (i = 3; exponent > 0; i++, exponent--) {
            printf("%c", string_num[i]);
        }
        putchar('.');
        for (; i < index_E; i++)
            printf("%c", string_num[i]);
    }
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
    int sign, length_after_point = 0;  //指数正负号，小数点后有效数字的长度

    scanf("%s", string_num);

    //先输出负号，正号不用输出
    if (string_num[0] == '-')
        putchar('-');

    for (int i=1; i < strlen(string_num); i++) {
        if (string_num[i] != 'E')
            continue;
        index_E = i;
        length_after_point = i - 3;
        sign = string_num[++i];     //存储指数的正负号
        while (string_num[++i] != '\0') {
            exponent = exponent * 10 + (string_num[i] - '0');
        }
        break;
    }
    
    //指数为0的情况
    if (!exponent) {
        for (int i=1; i < index_E; i++)
            printf("%c", string_num[i]);
        putchar('\n');
        return 0;
    }

    if (sign == '+')
        positive(string_num, exponent, index_E, length_after_point);
    else
        negative(string_num, exponent, index_E);

    putchar('\n');
    return 0;
}