#include <stdio.h>
#include <string.h>

int main()
{
	int M;
	char password[51];
	scanf("%d", &M);
	while (M--) {
		scanf("%s", password);
		int ch1 =0, ch2=0, ch3=0, ch4=0;
		int length;
		length = strlen(password);
		if (length < 8 || length > 16) {
			puts("NO");
			continue;
		}
		for (int j=0; j < length; j++) {
			if (password[j] <='Z' && password[j] >='A')
				ch1 =1;
			if (password[j] <='z' && password[j] >='a')
				ch2 =1;
			if (password[j] <='9' && password[j] >='0')
				ch3 =1;
			if (password[j]=='~' || password[j] =='^' || password[j] =='#' || 
					password[j]=='%'|| password[j]=='@' || password[j] =='!'||
					password[j]=='$')
				ch4 =1;
			if (ch1+ch2+ch3+ch4 > 2)
				break;
		}
		if (ch1+ch2+ch3+ch4 > 2)
			puts("YES");
		else puts("NO");
	}

	return 0;
}
