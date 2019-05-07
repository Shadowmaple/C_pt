# include <stdio.h>
# include <string.h>

struct information
{
    int id;
    int morality;
    int talent;
} student_info;

int main()
{
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    student_info student[N];

    for (int i=0; i < N; i++) {
        int id_x, moralty_x, talent_x;
        scanf("%d%d%d", &id_x, &moralty_x, &talent_x);
        if (morality_x<l || talent_x<l)
			continue;
    }

    return 0;
}