#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char str[101];
	scanf("%d", &n);
	while(n--) {
		getchar();
		scanf("%[^\n]", str);
		int length = strlen(str);
		int check=1;
		int lsum=0, msum=0, rsum=0;
		int p=0, t=0;
		for (int i=0; i < length; i++) {
			if (str[i]!='A' && str[i]!='P' && str[i]!='T') {
				check =0;
				break;
			}
			if (str[i]=='P') p++;
			else if (str[i]=='T') t++;
			else {
				if (p==0 && t==1) {
					check =0;
					break;
				}
				if (p==0)
					lsum++;
				else if(p>=1 && t==0)
					msum++;
				else
					rsum++;
			}
		}
		if (p!=1 || t!=1) check =0;
		if (msum==0 || lsum!=0 && rsum!=0 && lsum*msum != rsum) check=0;
		if (!check)
			puts("NO");
		else
			puts("YES");
	}

	return 0;
}
