# include <stdio.h>
# include <string.h>

void putcount(char *str, int count, int *index)
{
    if (count < 10)
		str[(*index)++] = count + '0';
	else {
		int i = 3;
		char x[5];
		x[4] = '\0';
		while (count > 0) {
			x[i--] = count % 10 + '0';
			count /= 10;
		}
		strcpy(str + *index, x + i + 1);
		*index += 3 - i;
	}
}

int main()
{
    char n, str[1001];
    scanf("%c", &n);
    getchar();

    int count = 0, index = -1;
    char pre, now;
    if (n == 'C') {
        while (1) {
            scanf("%c", &now);
            if (now == '\n') {
                if (count) putcount(str, count + 1, &index);
                str[index++] = pre;
                break;
            }
            if (index == -1) {
                pre = now;
                index++;
                continue;
            }
            if (now == pre) {
                count++;
            } else if (!count) {
                str[index++] = pre;
                pre = now;
            } else {
                putcount(str, count + 1, &index);
                str[index++] = pre;
                pre = now;
                count = 0;
            }
        }
    } else if (n == 'D') {
        index = 0;
        while (1) {
            scanf("%c", &now);
            if (now == '\n') break;
            if (now <= '9' && now >= '0') {
                if (!now)
                    count = now - '0';
                else
                    count = count * 10 + (now - '0');
            } else if (count) {
                while (count-- > 0)
                    str[index++] = now;
                count = 0;
            } else {
                str[index++] = now;
            }
        }
    }
    str[index] = '\0';
    printf("%s\n", str);

    return 0;
}
