#include<stdio.h>
#include<stdlib.h>
 struct Lnode
 {
 	int data;
 	struct Lnode *next;
 	
 };
 
 struct Lnode*p1=NULL;
  struct Lnode*p2=NULL;
   struct Lnode*p=NULL;
    struct Lnode*q1=NULL;
     struct Lnode*q2=NULL;
     struct Lnode*p3=NULL;
     struct Lnode*Q=NULL;
     
 
int main()
{
	
	 int i=0,j=0;
 
   p1=(struct Lnode*)malloc(sizeof(struct Lnode));
   p2=(struct Lnode*)malloc(sizeof(struct Lnode));
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
