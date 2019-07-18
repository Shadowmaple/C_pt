# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct
{
    char name[7];
    int score;
    int num;
} apartment;

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
    for (int i = 0; i < len; i++) {
        c[i] = tolower(c[i]);
    }
}

int cmpName(const void *a, const void *b)
{
    apartment *x = (apartment *) a, *y = (apartment *) b;
    return strcmp(x->name, y->name);
}

int cmpSearch(const void *a, const void *b)
{
    char *x = (char *) a;
    apartment *y = (apartment *) b;
    return strcmp(x, y->name);
}

int main()
{
    int n;
    scanf("%d", &n);
    apartment unit[n];
    int count = 0;
    char id[7], school[7];
    int score;
    for (int i = 0; i < n; i++) {
        unit[i].num = 0;
        unit[i].score = 0;

        scanf("%s %d %s", id, &score, school);
        convert(school);
        if (id[0] == 'B')   score /= 1.5;
        else if (id[0] == 'T')  score *= 1.5;
        void *flag = NULL;
        flag = bsearch(school, unit, count, sizeof(apartment), cmpSearch);
        if (flag != NULL) {
            ((apartment *) flag)->num++;
            ((apartment * )flag)->score += score;
        } else {
            strcpy(unit[count].name, school);
            unit[count].num = 1;
            unit[count++].score = score;
            qsort(unit, count, sizeof(apartment), cmpName);
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