/* 用递归方法求解 0/1 背包问题 */

#include<stdio.h>
#define MAXN 20         //最多物品数
int maxv;               //存放最优解的总价值
int maxw;               //存放最优解的总重量
int x[MAXN];            //存放最终解
int W = 7;              //限制的总重量
int n = 5;              //物品总数
int w[] = {5,3,2,1,1};  //物品重量
int v[] = {5,4,4,3,1};  //物品价值

void knap(int i,int tw,int tv,int op[])
{
    int j;

    if(i >= n)
    {
        if(tw <=W && tv > maxv)
        {
            maxv = tv;
            maxw = tw;
            for(j = 1;j <= n;j++)
                x[j] = op[j];
        }
    }
    else
    {
        op[i] = 1;
        knap(i + 1,tw + w[i],tv + v[i],op);
        op[i] = 0;
        knap(i + 1,tw,tv,op);
    }
}

void DispASolution(int x[],int n)
{
    int i;

    printf("最佳装填方案是：\n");
    for(i = 1;i <= n;i++)
        if(x[i] == 1)
            printf("\t选取第 %d 个物品\n",i);
    printf("\n总重量 = %d, 总价值 = %d\n",maxw,maxv);
}

int main()
{
    int op[MAXN];
    knap(0,0,0,op);
    DispASolution(x,n);

    return 0;
}
