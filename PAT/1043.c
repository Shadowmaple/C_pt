# include <stdio.h>
# include <string.h>

int main()
{
    int num[6] = {0};
    char s;
    while (1) {
        scanf("%c", &s);
        if (s == '\n')  break;
        switch (s) {
            case 'P': num[0]++; break;
            case 'A': num[1]++; break;
            case 'T': num[2]++; break;
            case 'e': num[3]++; break;
            case 's': num[4]++; break;
            case 't': num[5]++; break;
        }
    }

    int max = num[0];
    for (int i=0; i < 6; i++)
        max = (max > num[i])? max : num[i];
    
    for (int i=0; i < max; i++) {
        if (num[0]-- > 0) putchar('P');
        if (num[1]-- > 0) putchar('A');
        if (num[2]-- > 0) putchar('T');
        if (num[3]-- > 0) putchar('e');
        if (num[4]-- > 0) putchar('s');
        if (num[5]-- > 0) putchar('t');
    }
    putchar('\n');
    
    return 0;
}