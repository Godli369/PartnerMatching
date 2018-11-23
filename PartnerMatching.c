#define MAX  20
#include <stdlib.h>
#include <stdio.h>
typedef struct SqQueue{
	int *base;
	int front;
	int rear;
}SqQueue;//线性队列

void InitQueue(SqQueue *Q)
{//建立一个队列
	Q->base=(int*)malloc(MAX * sizeof(SqQueue));
	Q->front=Q->rear=0;
}

int EnQueue(SqQueue *Q,int e)//入队
{	if((Q->rear+1)%MAX==Q->front)
		exit(0);
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAX;
	return e;
}

int DeQueue(SqQueue *Q,int e)
{//将非空队列Q中的对头元素出队列

	if(Q->front==Q->rear)
		exit(0);
	e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAX;
	return e;
}

int GetHead(SqQueue Q,int e)
{//用e返回队列Q的对头元素
	if(Q.front==Q.rear)
		exit(0);
	e=Q.base[Q.front];
	return e;
	
}
void Party(SqQueue *Q1,SqQueue *Q2)
{//将队列Q1和Q2中的成员配对
	int i,m,w,xm,ls,k,j,x,y;
	printf("\n\n");
	printf("\t**************************************\n\n");
	printf("\t>>>>>>>>>>>>>>>舞伴配对<<<<<<<<<<<<<<<\n\n");
	printf("\t**************************************\n\n");
	printf("\t>>>>>>>>>>>>>>队列已创建<<<<<<<<<<<<<<<\n");
	printf("\t>>>>>>>>>>>>>请按提示操作<<<<<<<<<<<<<<\n\n");
	InitQueue(Q1);  
	printf("\t\t^^^请输入男舞伴人数^^^\n");
	scanf("\t\t%d",&m);
	printf("\t\t^^^请输入男舞伴编号^^^\n");
	for(i=0;i<m;i++)
	{
		scanf("\t\t%d",&xm);
		EnQueue(Q1,xm);
	}
	InitQueue(Q2);
	printf("\t\t^^^请输入女舞伴人数^^^\n");
	scanf("\t\t%d",&w);
	printf("\t\t^^^请输入女舞伴编号^^^\n");
	for(i=0;i<w;i++)
	{
		scanf("\t\t%d",&xm);
		EnQueue(Q2,xm);
	}
	printf("\t\t^^^请输入跳舞轮数^^^\n");
	scanf("\t\t%d",&ls);
	printf("\n");
	printf("\t************舞伴配对结果************\n\n");
    if(m>w)k=w;
	else k=m;
	for(i=0;i<ls;i++)
	{
		printf("\t\t^^^第%d轮出场配对:^^^\n",i+1);
		for(j=0;j<k;j++)
		{
		
			x=DeQueue(Q1,m);
			y=DeQueue(Q2,w);
			printf("\t\t%d<------->%d\n",x,y);
			EnQueue(Q1,x);
			EnQueue(Q2,y);
		}
		x=GetHead(*Q1,m);
		y=GetHead(*Q2,w);
	    printf("\t\t下一轮要配对的舞伴是：\n");
		printf("\t\t%d和%d\n\n",x,y);

	}
}

void main()
{   
	
	SqQueue Q1;
	SqQueue	Q2;
    Party(&Q1,&Q2);
	
}
