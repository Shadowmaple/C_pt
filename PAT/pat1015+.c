//改进地方：运用结构体，id用int型，使用库函数qsort

# include <stdio.h>
# include <stdlib.h>

struct information
{
    int id;
    int morality;
    int talent;
};
typedef struct information student_info;

int compare(const void *a, const void *b)
{
    student_info student1 = *(student_info *) a;
    student_info student2 = *(student_info *) b;
    if (student1.morality + student1.talent != student2.morality + student2.talent)
        //总分降序
        return student1.morality + student1.talent < student2.morality + student2.talent;
    else if (student1.morality != student2.morality)
        //德分降序
        return student1.morality < student2.morality;
    else
        //准考证号升序
        return student1.id > student2.id;
}

int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    int total[4] = {0};
    //四类学生总数
    student_info student[4][N];

    for (int i=0; i < N; i++) {
        student_info buffer;
        scanf("%d%d%d", &buffer.id, &buffer.morality, &buffer.talent);

        if (buffer.morality<L || buffer.talent<L)
			continue;
        if (buffer.morality >= H && buffer.talent >= H) {
            student[0][total[0]] = buffer;
            total[0]++;
        } else if (buffer.morality >= H) {
            student[1][total[1]] = buffer;
            total[1]++;
        } else if (buffer.morality >= buffer.talent) {
            student[2][total[2]] = buffer;
            total[2]++;
        } else {
            student[3][total[3]] = buffer;
            total[3]++;
        }
    }

    printf("%d\n", total[0] + total[1] + total[2] + total[3]);
    for (int i=0; i < 4; i++) {
        qsort(student[i], total[i], sizeof(student[0][0]), compare);
        for (int j=0; j < total[i]; j++) {
            printf("%d %d %d\n",
                student[i][j].id, student[i][j].morality, student[i][j].talent);
        }
        //puts("---");
    }

    return 0;
}