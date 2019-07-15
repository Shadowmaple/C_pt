# include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);    
    for (int i = 0; i < n; i++) {
        int teach_score, stu_score, sum = 0, count = 0;
        int max = 0, min = m;
        scanf("%d", &teach_score);
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &stu_score);
            if (stu_score < 0 || stu_score > m) continue;
            if (max < stu_score) max = stu_score;
            if (min > stu_score) min = stu_score;
            sum += stu_score;
            count++;
        }
        sum -= max + min;
        count -= 2;    
        float score = ((float) sum / count + teach_score) / 2 + 0.5;
        printf("%d\n", (int)score);

    }
    return 0;
}