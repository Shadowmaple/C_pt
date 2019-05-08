# include <stdio.h>
# include <stdlib.h>

struct cake
{
    //若库存量为整型，则有第二个测试点过不去
    float storage;    //每种月饼的库存量
    float price;     //每种月饼的总售价
    float unit_price; //月饼的单价
} mooncake[1000];

int compare(const void *a, const void *b)
{
    struct cake price1 = *(struct cake *) a;
    struct cake price2 = *(struct cake *) b;
    return price1.unit_price < price2.unit_price;
    //降序
}

int main()
{
    int kind, need;
    //输入种类数和需求量
    scanf("%d%d", &kind, &need);    
    
    //输入库存量
    for (int i=0; i < kind; i++)
        scanf("%f", &mooncake[i].storage);
    //输入总售价，并计算单价
    for (int i=0; i < kind; i++) {
        scanf("%f", &mooncake[i].price);
        mooncake[i].unit_price = mooncake[i].price / mooncake[i].storage;
    }
    qsort(mooncake, kind, sizeof(mooncake[0]), compare);

    float total = 0;
    for (int i=0; i < kind; i++) {
        if (mooncake[i].storage >= need) {
            total += need * mooncake[i].unit_price;
            break;
        }
        total += mooncake[i].storage * mooncake[i].unit_price;
        need -= mooncake[i].storage;
    }

    printf("%.2f\n", total);
    return 0;
}