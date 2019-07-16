# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct
{
    int codeScore;
    int midtermScore, finalScore;
    int grade;
    char name[21];
} student;

int compar(const void *a, const void *b)
{
    student x = *(student *) a, y = *(student *) b;
    if (x.grade > y.grade) return -1;
    else if (x.grade < y.grade) return 1;
    else if (strcmp(x.name, y.name) < 0) return -1;
    else return 1;
}

int main()
{
    int P, M, N;
    scanf("%d%d%d", &P, &M, &N);
    student stu[P + M + N];
    int count = 0;

    for (int i = 0; i < P + M + N; i++) {
        stu[i].codeScore = -1;
        stu[i].finalScore = -1;
        stu[i].midtermScore = -1;
    }

    for (int i = 0; i < P; i++, count++) {
        scanf("%s %d", stu[count].name, &stu[count].codeScore);
    }
    for (int i = 0; i < M; i++) {
        char x[21];
        int y, j, flag = 0;
        scanf("%s %d", x, &y);
        for (j = 0; j < count; j++) {
            if (!strcmp(x, stu[j].name)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            stu[j].midtermScore = y;
        } else {
            stu[count].midtermScore = y;
            strcpy(stu[count++].name, x);
        }
    }
    for (int i = 0; i < N; i++) {
        char x[21];
        int y, j, flag = 0;
        scanf("%s %d", x, &y);
        for (j = 0; j < count; j++) {
            if (!strcmp(x, stu[j].name)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            stu[j].finalScore = y;
        } else {
            stu[count].finalScore = y;
            strcpy(stu[count++].name, x);
        }
    }
    for (int i = 0; i < count; i++) {
        stu[i].grade = stu[i].midtermScore <= stu[i].finalScore ? stu[i].finalScore : \
                        stu[i].midtermScore * 0.4 + stu[i].finalScore * 0.6 + 0.5;
    }
    qsort(stu, count, sizeof(student), compar);
    for (int i = 0; i < count; i++) {
        if (stu[i].grade < 60) break;
        if (stu[i].codeScore < 200) continue;
        printf("%s %d %d %d %d\n", stu[i].name, stu[i].codeScore, 
                    stu[i].midtermScore, stu[i].finalScore, stu[i].grade);
    }

    return 0;
}