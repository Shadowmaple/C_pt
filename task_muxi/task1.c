#include<stdio.h>

int main()
{
	double a,b,c;
	puts("请输入边长：");
	printf("边长a：");         scanf("%lf",&a);
	printf("边长b：");         scanf("%lf",&b);
        printf("边长c：");         scanf("%lf",&c);
	
	if(a<0 || b<0 || c<0 )
		puts("请输入大于0的数！");
	else if( a==b && b==c )
		puts("1");
	else if( a==b ||a==c || b==c )
		puts("2");
	else if( a+b<=c || a+c<=b || b+c<=a )
		puts("0");
	else puts("3");

	return 0;	
}
