#include <stdio.h>
#include <string.h>

int main()
{
	char ideality[81], reality[81];
	scanf("%s", ideality);
	scanf("%s", reality);
	char item[80];
	int count =0;
	for (int i=0, j =0; i < strlen(ideality); i++, j++) {
			if (ideality[i] == reality[j])
				continue;
			j--;
			int check=1;
			if (ideality[i] >='a' && ideality[i] <='z')
				ideality[i] = ideality[i] - 32;
			for (int k=0; k < count; k++){
				if (item[k] == ideality[i]) {
					check =0;
					break;
				}
			}
			if (check)
				item[count++] = ideality[i];
	}
	for (int i=0; i < count; i++)
		putchar(item[i]);
	putchar('\n');

	return 0;
}
