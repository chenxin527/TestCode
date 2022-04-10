#include<stdio.h>
#include<stdlib.h>

typedef struct qnode
{
    int data;
    struct qnode* next;
} DataNode;

typedef struct
{
    DataNode *front,*rear;
} LinkQuNode;

void SeeDoctor(void);
void Enqueue(LinkQuNode* &qu,DataNode* &p);
void ReceiveTreatment(LinkQuNode* &qu,DataNode* &p);
void CheckQueue(LinkQuNode* &qu,DataNode* &p);
void StopEnqueuingAndReceiveTreatmentInOrder(LinkQuNode* &qu,DataNode* &p,int &flag);
void BeOffWork(LinkQuNode* &qu,DataNode* &p,int &flag);
void DestroyQueue(LinkQuNode* &qu,DataNode* &p);

int main(void)
{
    SeeDoctor();
    return 0;
}

void SeeDoctor(void)
{
    int selection;
    int flag=1;
    LinkQuNode *qu;
    DataNode *p;
    qu=(LinkQuNode *)malloc(sizeof(LinkQuNode)); 
    qu->front=qu->rear=NULL;

    printf("看病模拟程序！\n\n");
    while (flag==1)                             
    {
        printf("\n");
        printf("1:排队 2:就诊 3:查看排队 4.不再排队,余下依次就诊 5:下班  请选择:");
        scanf("%d",&selection);
        switch(selection)
        {
        case 1:
            Enqueue(qu,p);
            break;
        case 2:
            ReceiveTreatment(qu,p);
            break;
        case 3:
            CheckQueue(qu,p);
            break;
        case 4:
            StopEnqueuingAndReceiveTreatmentInOrder(qu,p,flag);
            break;
        case 5:
            BeOffWork(qu,p,flag);
            break;
        }
    }
    DestroyQueue(qu,p);
}

void Enqueue(LinkQuNode* &qu,DataNode* &p)
{
    int isfind,number;

    printf("\n");
    printf("  >>请输入病历号:");
    do
    {
        scanf("%d",&number);
        isfind=0;
        p=qu->front;
        while (p!=NULL && isfind == 0)
        {
            if (p->data==number)
                isfind=1;
            else
                p=p->next;
        }
        if (isfind)
            printf("  >>输入的病历号重复,重新输入:");
    }while (isfind==1);

    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=number;
    p->next=NULL;
    if (qu->rear==NULL)                 /*第一个病人排队*/
    {
        qu->front=qu->rear=p;
    }
    else
    {
        qu->rear->next=p;
        qu->rear=p; /*将*p结点入队*/
    }

}

void ReceiveTreatment(LinkQuNode* &qu,DataNode* &p)
{
    if (qu->front==NULL)                /*队空*/
        printf("  >>没有排队的病人!\n");
    else                                /*队不空*/
    {
        p=qu->front;
        printf("  >>病人%d就诊\n",p->data);
        if (qu->rear==p)            /*只有一个病人排队的情况*/
        {
            qu->front=qu->rear=NULL;
        }
        else
            qu->front=p->next;
        free(p);
    }
}

void CheckQueue(LinkQuNode* &qu,DataNode* &p)
{
    if (qu->front==NULL)            /*队空*/
        printf("  >>没有排列的病人!\n");
    else                            /*队不空*/
    {
        p=qu->front;
        printf("  >>排队病人:");
        while (p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void StopEnqueuingAndReceiveTreatmentInOrder(LinkQuNode* &qu,DataNode* &p,int &flag)
{
    if (qu->front==NULL)            /*队空*/
        printf("  >>没有排列的病人!\n");
    else                            /*队不空*/
    {
        p=qu->front;
        printf("  >>病人按以下顺序就诊:");
        while (p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    flag=0;                         /*退出*/

}

void BeOffWork(LinkQuNode* &qu,DataNode* &p,int &flag)
{
    if (qu->front!=NULL)            /*队不空*/
        printf("  >>请排队的病人明天就医!\n");
    flag=0;                     /*退出*/
}

void DestroyQueue(LinkQuNode* &qu,DataNode* &p)
{
    p=qu->front;  //销毁队列
    DataNode* q;
    while (p!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}