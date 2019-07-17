# include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int champion, loser;
    int max = 0, min = 20000;
    int id, x, y, score;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &x, &y);
        score = x * x + y * y;
        if (max < score) {
            max = score;
            loser = id;
        }
        if (min > score) {
            min = score;
            champion = id;
        }
    }
    printf("%04d %04d\n", champion, loser);

    return 0;
}