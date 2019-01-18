#include <stdio.h>
#include <string.h>

int main()
{
	char st[100];
	scanf("%[^\n]", st);
	int count=0, minus=0;
	int n[100], m[100];
	for (int i=0, cycle=1; i<strlen(st); i++) {
		if (st[i]==' ') {
			k = i;
			continue;
		}
		if (st[i]=='-') {
			minus = 1;
			continue;
		}
		if (cycle == 1) {
			n[count] = st[i]-'0';
			if (minus) {
				n[count] = -n[count];
				minus=0;
			}
			cycle = 2;
		} else {
			m[count] = st[i]-'0';
			if (minus) {
				m[count] = -m[count];
				minus = 0;
			}
			cycle = 1;
			n[count] *= m[count];
			m[count++]--;
		}
	}
	int flag = 0;
	for (int i=0; i<count; i++) {
		if (n[i]) {
			if (flag) {
				printf(" %d %d", n[i], m[i]);
			} else {
				printf("%d %d", n[i], m[i]);
				flag = 1;
			}
		}
	}
	if (!flag)
		printf("0 0");

	putchar('\n');
	return 0;
}
