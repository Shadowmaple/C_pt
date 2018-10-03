#include <stdio.h>

int main()
{
	int m1, m2;
	float grade1, grade2;

	puts("请输入成绩。");
	printf("成绩1：");
	scanf("%f", &grade1);
	printf("成绩2：");
	scanf("%f", &grade2);
	m1 = grade1/10;
	m2 = grade2/10;

	switch (m1)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: puts("it is not pass."); break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10: if(grade1 >100 || grade2 >100)
			 	{puts("it is error.");break;}
			else switch (m2)
				{
					case 0:
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:puts("it is not pass."); break;
					case 6:
					case 7:
					case 8:
					case 9:
					case 10:puts("it is pass."); break;
					default:puts("it is error.");
				}
			break;
		default : puts("it is error.");
	}

	return 0;
}
