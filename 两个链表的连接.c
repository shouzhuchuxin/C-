#include<stdio.h>
#include<stdlib.h>
//创建结构体包含数据域和指针域
 struct Lnode
 {
 	int data;
 	struct Lnode *next;
 	
 };
 
 struct Lnode*p1=NULL;//第一个链表的头节点
  struct Lnode*p2=NULL;//第二个
   struct Lnode*p=NULL;//开辟动态空间使用的指针
    struct Lnode*q1=NULL;//第一个链表中指向始终指向最后一个节点的指针，用来进行链表的链接
     struct Lnode*q2=NULL;//第二个
     struct Lnode*p3=NULL;//这个是进行两个链表链接时，新创建的链表的跟随指针，用来进行链表的链接
     struct Lnode*Q=NULL;//这个是上面那个指针的头节点
     
 
int main()
{
	
	 int i=0,j=0;
 //这里注意：当创建的链表有头节点时记得对头节点创建空间
   p1=(struct Lnode*)malloc(sizeof(struct Lnode));
   p2=(struct Lnode*)malloc(sizeof(struct Lnode));
	//对第一个链表进行赋值
 while(i<=3)
{
	p=( struct Lnode*)malloc(sizeof(struct Lnode));
	if(p==NULL)
	printf("error\n");
	if(i==0)
	{
		p1->next=p;	
		q1=p;
	}
    else
    {
    	q1->next=p;	
    	q1=p;
	}
    
	p->data=i;
	p->next=NULL;
	i++;
	printf("%d",q1->data);
	
 } 
 printf("\n");
	//对第二个链表进行赋值
 while(j<=7)
 {
 	p=( struct Lnode*)malloc(sizeof(struct Lnode));
	if(j==0)
	{
		q2=p;
		p2->next=p;
	}
	else
    {
    	q2->next=p;	
    	q2=p;
	}
	p->data=j;
	p->next=NULL;
	j++;
		printf("%d",q2->data);
 }
 printf("\n");
	//使新创建的头节点p3以p1的位置为起点进行后续链表的链接
 p3=Q=p1;
 p1=p1->next;
 p2=p2->next;
 while(p1&&p2)
 {
 	if(p1->data>p2->data)
 	{
 		p3->next=p2;
		 p3=p2;
 		p2=p2->next;
 	
	 }
	 else if(p1->data<p2->data)
	 {
	 	p3->next=p1;
	 	p3=p1;
	 	p1=p1->next;
	 
	 }
	 else 
	 {
	 	p3->next=p1;
	 	p3=p1;
	 	p1=p1->next;
	 	p3->next=p2;
	 	p3=p2;
	 	p2=p2->next;	
	 }
	 
 }
 while(p1!=NULL)
 {
 	p3->next=p1;
 	p3=p1;
 	p1=p1->next;

 }
 while(p2!=NULL)
 {
 	p3->next=p2;
 	p3=p2;
 	p2=p2->next;
 
 }
	//注意Q的指向
 Q=Q->next;
 while(Q)
 {
 	printf("%d",Q->data);
 	Q=Q->next;	
 }
 free(p1);
 free(p2);
 free(p3);
	return 0;
 } 
