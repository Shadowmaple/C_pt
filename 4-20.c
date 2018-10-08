#include <stdio.h>

int main()
{
	for (int i=-1;i <= 9;++i)
	{
		for (int j=-1;j <= 9;++j)
			if (i == 0)
			{
				if (j <= 0) printf("--");
				else printf("---");
			}
			else if (i == -1)
			{
				if (j == -1) printf("  ");
				else if (j == 0) printf("| ");
				else printf("%3d",j);
			}
			else
			{
				if (j == -1) printf("%d ",i);
				else if(j == 0) printf("| ");
				else printf("%3d", i*j);
			}
		putchar('\n');
	}
        return 0;
}
