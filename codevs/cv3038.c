#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int m[n], s[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &m[i]);
		s[i] = 0;
		while (m[i]!=1) {
			if (m[i]%2)
				m[i] = m[i]*3+1;
			else
				m[i] /=2;
			s[i]++;
		}
	}
	for (int i=0; i <n; i++)
		printf("%d\n", s[i]);
	
	return 0;
}
