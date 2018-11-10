#include <stdio.h>
int main()
{
    int n, k;
	double Sn = 0;

    do {
        scanf("%d", &k);

        if (k > 0 && k < 16) {
            for (n = 1; Sn <= k; n++) {
                Sn += (double) 1/n;
            }
        } else {
            puts("error!");
        }
    } while (k < 1 || k > 15);

    printf("%d\n", n - 1);
    return 0;
}
