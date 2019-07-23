# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct
{
    char id[13];
    int score;
} student;

typedef struct
{
    char room[4];
    int num;
} examRoom;

int cmp(const void *a, const void *b)
{
    student *x = (student *) a, *y = (student *) b;
    if (x->score != y->score)
        return y->score - x->score;
    else
        return strcmp(x->id, y->id);
}

int cmp3(const void *a, const void *b)
{
    examRoom *x = (examRoom *) a, *y = (examRoom *) b;
    if (x->num != y->num)
        return y->num - x->num;
    else
        return strcmp(x->room, y->room);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    student stu[n];
    for (int i = 0; i < n; i++)
        scanf("%s %d", stu[i].id, &stu[i].score);

    qsort(stu, n, sizeof(student), cmp);

    int model;
    char require[7];
    for (int i = 0; i < m; i++) {
        scanf("%d %s", &model, require);
        printf("Case %d: %d %s\n", i + 1, model, require);
        int flag = 0;
        if (model == 1) {
            for (int j = 0; j < n; j++) {
                if (require[0] == stu[j].id[0]) {
                    printf("%s %d\n", stu[j].id, stu[j].score);
                    flag = 1;
                }
            }
        } else if (model == 2) {
            int scoreTotal = 0, stuNum = 0;
            for (int j = 0; j < n; j++) {
                if (!strncmp(require, stu[j].id + 1, 3)) {
                    stuNum++;
                    scoreTotal += stu[j].score;
                    flag = 1;
                }
            }
            if (flag) printf("%d %d\n", stuNum, scoreTotal);
        } else {
            examRoom room[1000] = {0};
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (!strncmp(require, stu[j].id + 4, 6)) {
                    char x[4];
                    strncpy(x, stu[j].id + 1, 3);
                    x[3] = '\0';
                    if (room[atoi(x)].num == 0) {
                        strcpy(room[atoi(x)].room, x);
                        count++;
                    }
                    room[atoi(x)].num++;
                }
            }
            if (count) {
                flag = 1;
                examRoom re[count];
                for (int j = 0, index = 0; index < count && j < 1000; j++) {
                    if (room[j].num) {
                        strcpy(re[index].room, room[j].room);
                        re[index++].num = room[j].num;
                    }
                }
                qsort(re, count, sizeof(examRoom), cmp3);
                for (int j = 0; j < count; j++)
                    printf("%s %d\n", re[j].room, re[j].num);
            }
        }
        if (!flag) puts("NA");
    }

    return 0;
}