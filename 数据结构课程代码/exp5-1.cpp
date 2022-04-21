/* 采用递归和非递归方法求解 Hanoi 问题 */

#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

void Hanoi1(int n,char a,char b,char c)
{
    if(n == 1)
        printf("\t将第 %d 个盘片从 %c 移动到 %c\n",n,a,c);
    else
    {
        Hanoi1(n-1,a,c,b);
        printf("\t将第 %d 个盘片从 %c 移动到 %c\n",n,a,c);
        Hanoi1(n-1,b,a,c);
    }
}

typedef struct
{
    int n;
    char x,y,z;
    bool flag;
}ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
}StackType;

void InitStack(StackType *&s)
{
    s = (StackType *)malloc(sizeof(StackType));
    s->top = -1;
}

void DestroyStack(StackType *&s)
{
    free(s);
}

bool StackEmpty(StackType *s)
{
    return (s->top == -1);
}

bool Push(StackType *&s,ElemType e)
{
    if(s->top == MaxSize - 1)
        return false;
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(StackType *&s,ElemType &e)
{
    if(s->top == -1)
        return false;
    e = s->data[s->top];
    s->top--;
    return true;
}

void Hanoi2(int n,char x,char y,char z)
{
    StackType *st;
    ElemType e,e1,e2,e3;
    
    if(n <= 0)
        return;
    InitStack(st);

    e.n = n;
    e.x = x;
    e.y = y;
    e.z = z;
    e.flag = false;
    
    Push(st,e);
    while(!StackEmpty(st))
    {
        Pop(st,e);
        if(e.flag == false)
        {
            e1.n = e.n - 1;
            e1.x = e.y;
            e1.y = e.x;
            e1.z = e.z;
            if(e1.n == 1)
                e1.flag = true;
            else 
                e1.flag = false;
            Push(st,e1);
            e2.n = e.n;
            e2.x = e.x;
            e2.y = e.y;
            e2.z = e.z;
            e2.flag = true;
            Push(st,e2);
            e3.n = e.n - 1;
            e3.x = e.x;
            e3.y = e.z;
            e3.z = e.y;
            if(e3.n == 1)
                e3.flag = true;
            else e3.flag = false;
            Push(st,e3);
        }
        else    
            printf("\t将第 %d 个盘片从 %c 移动到 %c\n",e.n,e.x,e.z);
    }
    DestroyStack(st);
}

int main()
{
    int n = 3;

    printf("递归算法：%d 个盘片移动过程：\n",n);
    Hanoi1(n,'X','Y','Z');
    printf("\n");
    printf("非递归算法：%d 个盘片移动过程：\n",n);
    Hanoi2(n,'X','Y','Z');

    return 0;
}
