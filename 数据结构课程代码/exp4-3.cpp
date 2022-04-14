#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
typedef struct
{
    char data[MaxSize];
    int length;
}SqString;

int Index(SqString s,SqString t);
void GetNext(SqString t,int next[]);
void DestroyStr(SqString &s);
int KMPIndex(SqString s,SqString t);
void GetNextval(SqString t,int nextval[]);
int KMPIndex1(SqString s,SqString t);
void StrAssign(SqString &s,char cstr[]);
void DestroyStr(SqString &s);
void DispStr(SqString s);

int main(void)
{
    int j;
    int next[MaxSize],nextval[MaxSize];
    SqString s,t;

    StrAssign(s,"abcabcdabcdeabcdefabcdefg");
    StrAssign(t,"abcdeabcdefab");
    printf("串 s: ");
    DispStr(s);
    printf("串 t:");
    DispStr(t);
    printf("\n简单匹配算法:\n");
    printf("\tt 在 s 中的位置 = %d\n",Index(s,t));
    GetNext(t,next);
    GetNextval(t,nextval);
    printf("       j");
    for(j = 0;j < t.length;j++)
        printf("%4d",j);
    printf("\n");
    printf("    t[j]");
    for(j = 0;j < t.length;j++)
        printf("%4c",t.data[j]);
    printf("\n");
    printf("    next");
    for(j = 0;j < t.length;j++)
        printf("%4d",next[j]);
    printf("\n");
    printf(" nextval");
    for(j = 0;j < t.length;j++)
        printf("%4d",nextval[j]);
    printf("\n");
    printf("\nKMP 算法:\n");
    printf("\tt 在 s 中的位置 = %d\n",KMPIndex(s,t));
    printf("\n改进的 KMP 算法:\n");
    printf("\tt 在 s 中的位置 = %d\n",KMPIndex1(s,t));
    DestroyStr(s);
    DestroyStr(t);

    return 0;
}

int Index(SqString s,SqString t)
{
    int i = 0;
    int j = 0;

    while(i < s.length && j < t.length)
    {
        if(s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= t.length)
        return (i - t.length);
    else
        return (-1);
}

void GetNext(SqString t,int next[])
{
    int j,k;
    j = 0;
    k = -1;
    next[0] = -1;

    while(j < t.length - 1) 
    {
        if(k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

int KMPIndex(SqString s,SqString t)
{
    int next[MaxSize];
    int i = 0;
    int j = 0;

    GetNext(t,next);
    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j >= t.length)
        return (i - t.length);
    else
        return (-1);
}

void GetNextval(SqString t,int nextval[])
{
    int j = 0;
    int k = -1;
    nextval[0] = -1;

    while(j < t.length)
    {
        if(k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            if(t.data[j] != t.data[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}

int KMPIndex1(SqString s,SqString t)
{
    int nextval[MaxSize];
    int i = 0;
    int j = 0;

    GetNextval(t,nextval);
    while(i < s.length && j < t.length)
    {
        if(j == -1 || s.data[i] == t.data[j])
        {
            i++;
            j++;
        }
        else    
            j = nextval[j];
    }
    if(j >= t.length)
        return (i - t.length);
    else
        return (-1);
}

void StrAssign(SqString &s,char cstr[])
{
    int i;
    for(i = 0;cstr[i] != '\0';i++)
        s.data[i] = cstr[i];
    s.length = i;
}

void DestroyStr(SqString &s)
{ };

void DispStr(SqString s)
{
    int i;
    if(s.length > 0)
    {
        for(i = 0;i < s.length;i++)
            printf("%c",s.data[i]);
        printf("\n");
    }
}
