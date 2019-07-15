# include <stdio.h>
# include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char psw[101], letter, answer;
    int index = 0;
    
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
			scanf("%c-%c", &letter, &answer);
			if (answer == 'T') {
				switch (letter) {
					case 'A': psw[index++] = '1'; break;
					case 'B': psw[index++] = '2'; break;
					case 'C': psw[index++] = '3'; break;
					case 'D': psw[index++] = '4'; break;
				}
			}
            getchar();
        }
    }
    psw[index] = '\0';
    printf("%s\n", psw);

    return 0;
}
