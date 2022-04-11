#include<stdio.h>
#define M 4
#define N 4
#define MaxSize 100

int mg[M+2][N+2] = 
{
    {1,1,1,1,1,1},{1,0,0,0,1,1},{1,0,1,0,0,1},
    {1,0,0,0,1,1},{1,1,0,0,0,1},{1,1,1,1,1,1}
};
struct
{
    int i,j;
    int di;
}St[MaxSize],Path[MaxSize];
int top = -1;
int count = 1;
int minlen = MaxSize;

void mgPath(int xi,int yi,int xe,int ye);
void DispAPath(void);
void DisMinPath(void);

int main(void)
{
    printf("迷宫所有路径如下:\n");
    mgPath(1,1,M,N);

    return 0;
}

void mgPath(int xi,int yi,int xe,int ye)
{
    int i,j,i1,j1,di;
    bool find;
    top++;
    St[top].i =xi;
    St[top].j =yi;
    St[top].di = -1;
    mg[xi][yi] = -1;

    while(top > -1)
    {
        i = St[top].i;
        j = St[top].j;
        di = St[top].di;

        if(i == xe && j == ye)
        {
            DispAPath();
            mg[i][j] = 0;
            top--;
            i = St[top].i;
            j = St[top].j;
            di = St[top].di;
        }
        find = false;
        while(di < 4 && !find)
        {
            di++;
            switch(di)
            {
                case 0:
                    i1 = i - 1;
                    j1 = j;
                    break;
                case 1:
                    i1 = i;
                    j1 = j + 1;
                    break;
                case 2:
                    i1 = i + 1;
                    j1 = j;
                    break;
                case 3:
                    i1 = i;
                    j1 = j - 1;
                    break;
            }
            if(mg[i1][j1] == 0)
                find = true;
        }
        if(find)
        {
            St[top].di = di;
            top++;
            St[top].i = i1;
            St[top].j = j1;
            St[top].di = -1;
            mg[i1][j1] = -1;
        }
        else
        {
            mg[i][j] = 0;
            top--;
        }
    }
    DisMinPath();
}

void DispAPath(void)
{
    int k;

    printf("%5d:",count++);
    for(k = 0;k <= top;k++)
        printf("(%d,%d)",St[k].i,St[k].j);
    printf("\n");
    if(top + 1 < minlen)
    {
        for(k = 0;k <= top;k++)
            Path[k] = St[k];
        minlen = top + 1;
    }
}

void DisMinPath(void)
{
    int k;

    printf("最短路径如下:\n");
    printf("最短路径的长度为: %d\n",minlen);
    printf("最短路径为: ");
    for(k = 0;k < minlen;k++)
        printf("(%d,%d)",Path[k].i,Path[k].j);
    printf("\n");
}