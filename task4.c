#include <stdio.h>

int gc(int a, int b)
{
	int x;
	while (x != 0) {
		
		x=a % b;
	}
}
int main()
{
	int a,b,c,d;
	do {	
		puts("Please enter two postive integer:");
		scanf("%d%d", &a,&b);
		if (a<=0 || b<=0) puts("error!");
		if (a==b) puts("MUST DIFFERENT!");
	} while (a<=0 || b<=0 || a==b);
	
	if (a<b) {d=a;a=b;b=d;}

	c = gc(a,b);
	return 0;
}
