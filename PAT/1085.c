# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct
{
    char name[7];
    int score, num;
} apartment;

typedef struct
{
    char id[7], school[7];
    int score;
} student;

int compar(const void *a, const void *b)
{
    apartment *x = (apartment *) a, *y = (apartment *) b;
    if (x->score != y->score)   return -(x->score - y->score);
    else if (x->num != y->num)  return x->num - y->num;
    else                        return strcmp(x->name, y->name);
}

void convert(char *c)
{
    int len = strlen(c);
    for (int i = 0; i < len; i++)
        c[i] = tolower(c[i]);
}

int cmpName(const void *a, const void *b)
{
    student *x = (student *) a, *y = (student *) b;
    return strcmp(x->school, y->school);
}

int main()
{
    int n;
    scanf("%d", &n);
    apartment unit[10000] = {0};
    student stu[n];
    int count = 0;
    char id[7], school[7];
    int score;

    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", stu[i].id, stu[i].score, stu[i].school);
        convert(stu[i].school);
        if (stu[i].id[0] == 'B') stu[i].score /= 1.5;
        else if (stu[i].id[0] == 'T') stu[i].score *= 1.5;
    }
    qsort(stu, n, sizeof(student), cmpName);

    for (int i = 0; i < n; i++) {
        if (!i || strcmp(stu[i].school, stu[i - 1].school)) {
            strcpy(unit[count].name, stu[i].id);
            unit[count].num = 1;
            unit[count++].score = stu[i].score;
        } else {
            unit[count].num++;
            unit[count].score += stu[i].score;
        }
    }
    qsort(unit, count, sizeof(apartment), compar);

    printf("%d\n", count);
    for (int i = 0, rank = 1; i < count; i++) {
        if (!i) {
            printf("%d %s %d %d\n", rank, unit[i].name, unit[i].score, unit[i].num);
            continue;
        }
        if (unit[i].score == unit[i-1].score)
            printf("%d %s %d %d\n", rank, unit[i].name, unit[i].score, unit[i].num);
        else
            printf("%d %s %d %d\n", rank = i + 1, unit[i].name, unit[i].score, unit[i].num);
    }

    return 0;
}