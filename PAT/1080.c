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

int cmpName(const void *a, const void *b)
{
    student x = *(student *) a, y = *(student *) b;
    return strcmp(x.name, y.name);
}

int cmpSearch(const void *a, const void *b)
{
    char *x = (char *) a;
    student *y = (student *) b;
    return strcmp(x, y->name);
}

int main()
{
    int P, M, N;
    scanf("%d%d%d", &P, &M, &N);
    student stu[10000] = {0};
    int count = 0, mark;
    char name[21];

    for (int i = 0; i < P; i++) {
        scanf("%s %d", name, &mark);
        if (mark < 200) continue;
        strcpy(stu[count].name, name);
        stu[count].codeScore = mark;
        stu[count].midtermScore = -1;
        stu[count].finalScore = -1;
        count++;
    }
    qsort(stu, count, sizeof(student), cmpName);

    void *result;
    for (int i = 0; i < M; i++) {
        scanf("%s %d", name, &mark);
        result = bsearch(name, stu, count, sizeof(student), cmpSearch);
        if (result != NULL)
            (*(student *) result).midtermScore = mark;
    }
    for (int i = 0; i < N; i++) {
        scanf("%s %d", name, &mark);
        result = bsearch(name, stu, count, sizeof(student), cmpSearch);
        if (result != NULL) {
            student *s = (student *) result;
            s->finalScore = mark;
            s->grade = s->midtermScore <= s->finalScore ? s->finalScore : \
                        s->midtermScore * 0.4 + s->finalScore * 0.6 + 0.5;
        }
    }
    qsort(stu, count, sizeof(student), compar);
    
    for (int i = 0; i < count; i++) {
        if (stu[i].grade < 60) break;
        printf("%s %d %d %d %d\n", stu[i].name, stu[i].codeScore, 
                    stu[i].midtermScore, stu[i].finalScore, stu[i].grade);
    }

    return 0;
}