# include <stdio.h>
# include <math.h>

void sort(int *n1, int *n2, int N)
{
    char m[4];
    int num1 = 0, num2 = 0;

    for (int i=0; i<4; i++) {
        m[i] = N % 10 + '0';
        N /= 10;
    }
    for (int i=0; i < 4; i++) {
        int k = i;
        for (int j=i+1; j < 4; j++) {
            if (m[k] - '0' > m[j] - '0')
                k = j;
        }
        if (k != i) {
            int x = m[k];
            m[k] = m[i];
            m[i] = x;
        }

        num1 = num1 + (m[i]- '0') * pow(10, i);
        num2 = num2 * 10 + (m[i] - '0');
    }

    *n1 = num1;
    *n2 = num2;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num1, num2;

    // 使用do语句是考虑到输入为6174的情况
    do {
        sort(&num1, &num2, N);
        if (num1 == num2) {
            printf("%4d - %4d = 0000\n", N, N);
            return 0;
        }
        N = num1 - num2;
        printf("%04d - %04d = %04d\n", num1, num2, N);
    } while (N != 6174);

    return 0;
}