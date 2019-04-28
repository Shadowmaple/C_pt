#include <stdio.h>
#include <string.h>

int main()
{
	char A[10000], B[10000];
	char Da, Db;
	int Pa=0, Pb=0;
	scanf("%s %c %s %c", A, &Da, B, &Db);
	for (int i=0; i < strlen(A); i++)
		if (A[i] == Da)
			Pa = Pa*10 + (Da-'0');
	for (int i=0; i < strlen(B); i++)
		if (B[i] == Db)
			Pb = Pb*10 + (Db-'0');

	printf("%d\n", Pa+Pb);

	return 0;
}
