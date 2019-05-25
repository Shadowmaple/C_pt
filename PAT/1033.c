# include <stdio.h>
# include <string.h>
# include <ctype.h>

int match(char *bad_key, char c)
{
    for (int i=0; i < strlen(bad_key); i++) {
        if (c >= 'A' && c <= 'Z') {
            if (c == bad_key[i] || bad_key[i] == '+')
                return 0;
        } else if (c >= 'a' && c <= 'z') {
            if (bad_key[i] == toupper(c))
                return 0;
        } else {
            if (bad_key[i] == c)
                return 0;
        }
    }
    return 1;
}

int main()
{
    char bad_key[1000];
    char sentence[100001];
    scanf("%s%s", bad_key, sentence);
    char result[100001];

    int length = 0;
    for (int i=0; i < strlen(sentence); i++) {
        char c = sentence[i];
        if (c == '_' || c == '+' || match(bad_key, c)) {
            result[length++] = c;
        }
    }
    if (!length)
        puts(" ");
    result[length] = '\0';
    printf("%s\n", result);

    return 0;
}