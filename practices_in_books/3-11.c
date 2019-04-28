#include <stdio.h>

int main()
{
	int A,B,C,D;

	printf("整数A："); scanf("%d", &A);
	printf("整数B："); scanf("%d", &B);

	C = (A >= B) ? A:B;
	D = (A < B) ? A:B;
	
	if(C-D < 10 || C-D == 10) 
		puts("它们的差小于等于10。");
	else puts("它们的差大于等于10。");

        return 0;
}
