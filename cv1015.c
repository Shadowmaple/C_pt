#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char st[100], word;
	scanf("%s", st);
	double x_i=0, y_i=0;
	int len = strlen(st);
	int v;

	//获取未知数字母
	for (int i=0; i<len; i++) {
		if (st[i]>='a' && st[i]<='z')
			word = st[i];
		else if (st[i]=='=')
			v = i;
			//获取等号的位置
	}
	for(int i=0; i<len;) {
		int minus = 0;
		//负号
		//负号开头的情况
		if ((i==0 || i==v+1) && st[i]=='-'){
			i+=1;
			minus = 1;
		} else if (st[i-1]=='-')
			minus = 1;

		int end = i, sum=0;
		while (st[end]>='0' && st[end]<='9')
			end++;
		//此时end为未知数或正负号或等号
		//下标[i~end-1]之间的字符串为正整数, sum存储这个数
		for (int h=end-1, g=1; h>=i; h--) {
			sum += (st[h]-'0')*g;
			g *=10;
		}
		//负数取反
		if (minus) sum*=-1;
		if (i>v) sum*=-1;
		//等号右边则取相反数

		if (st[end]==word)
			x_i += sum;
		else y_i += sum;
		i = end+1;
	}
	double result = (-1)*(y_i)/x_i;
	if (result==0)
		result = abs(result);
	//为0时的情况
	printf("%c=%.3f\n", word, result);

	return 0;
}
