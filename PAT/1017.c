# include <stdio.h>
# include <string.h>

int main()
{
    int divisor;    //除数B
    char dividend[1001];    //被除数A
    char quotient[1001];    //商数Q
    int remaind = 0;      //余数R

    scanf("%s%d", dividend, &divisor);

    int length = strlen(dividend);
    int k = 0;
    
    for (int i=0; i < length; i++) {
        int num = dividend[i] - '0' + remaind * 10;
        //第一位小于除数情况，还有最后一位的情况
        if (num < divisor && i != length-1) {
            num = num * 10 + (dividend[++i] - '0');
            if (i != 1)
                quotient[k++] = '0';
        }
        quotient[k++] = num / divisor + '0';
        remaind = num % divisor;
    }
    quotient[k] = '\0';

    printf("%s %d\n", quotient, remaind);
    return 0;
}
