#include <stdio.h>

int main()
{
	int x, y;

	do {
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;
		else {
			int ch='T';
			for (int i =x; i <=y; i++) {
				int num = i*i+i+41;
				for (int j =2; j < num; j++) {
					if (num % j == 0) {
						ch = 'F';
						break;
					}
				
						
				}
				if (ch == 'F')
					break;
			
			
			
			}
			if (ch == 'F')
				puts("Sorry");
			else
				puts("OK");

		}
	} while (1);

	return 0;

}
