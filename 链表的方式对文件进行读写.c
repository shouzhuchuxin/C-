#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
typedef struct Z
{
	int a;
	int b;
	int c;
	struct Z*next;
}z;


int n=0;
int count=0; 
	z*head = NULL;  //head是头节点 
	   z*q = NULL;  //用q来表示每次生成链表的最后一个的位置以方便进行与下一个链表的连接 
	   
	   void goto_xy(int x, int y) 
{
	HANDLE hout; 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };  
	SetConsoleCursorPosition(hout, pos);  
}


//用 Register函数生成账号和密码，用Save函数将其保存在文件中
//然后在下一次运行该程序时将文件中的数据直接放到链表中
//问题是：当文件中有两组数据时，通过n显示只有一组数据得到了存放 

int Register()
{

	z*p=NULL;
	while(1)
	{
	system("cls");
	goto_xy(12,2);
	printf("您随机生成的账号为：\n");
		
	srand((unsigned)time(NULL));
	
	 		 
	//通过链表存放生成的数据 
   p=(z*)malloc(sizeof(z));
   if(p==NULL)
    {
    		printf("%s\n",strerror(errno));
	}
	
	p->a=100000+ rand()%900000;
	//第一次运行时要有head来指向头节点 
	if(n == 0)
	{
		head = p;
		q=p;
	
	 } 
	 
	printf("%d\n",p->a);
	 
	 printf("请输入一个六位数的密码。\n");
	 while(1)
	 {
	 	scanf("%d",&(p->b));
	 	if(!((p->b>=100000)&&(p->b<=999999)))
	 		printf("输入位数大于或小于六位，请重新输入！\n");
	 	else
	 		break;
	 }
	 
	 p->next=NULL;
	 p->c=0;
	 
	 if(n!=0)//以后运行时只需要q来指向新生成的链表位置 
	 {
	 	q->next=p;
	 	q=p;
		 
	 }
	 n++;
	 count++;
	 return 1;
	
		}
	
}	

//将数据保存在文件中 
void Save()
{
	int number=0;
	z*v=NULL;
	FILE*p=fopen("text.txt","w");
	 if(p==NULL)
	 printf("操作错误，无法保存！\n");
	 while(1)
	 {
	 	if(number==0)
	 	{
	 		fprintf(p,"%d %d %d\n",head->a,head->b,head->c);
	 		v=head->next;
		 }
		 else if(number!=0)
		 {
		 	fprintf(p,"%d %d %d\n",v->a,v->b,v->c);
	 		v=v->next;
		 }
		 number++;
		 if(v==NULL)
		 {
		 	fclose(p);
		 	printf("保存成功！\n");
		 	Sleep(2000);
		 	p=NULL;
			 return ;
		 }
		 
	 }
	 
 } 
 
 //运行程序时将文件中的数据保存在链表中，每组数据都需要通过新开辟的链表来保存
 //并且当使用Register函数生成新的链表时能将它们与Begain函数生成的链表连接起来 
 
 //主要是这个Begain函数有问题，，，， 
 void Begain()
{
	 	z*x=NULL;
 FILE*p=fopen("text.txt","r");
	while(1)
	{
	  
	   	x=(z*)malloc(sizeof(z));
	   int v=fscanf(p,"%d%d%d",&(x->a),&(x->b),&(x->c));
	   
	
		if(x==NULL) 
      {
    		printf("%s\n",strerror(errno));
	  }
	 
	  
	    if(v==EOF)
	  {
	  	fclose(p);
	  	p=NULL;
	  	free(x);
	  	x=NULL;
	  	printf("输入成功！"); 
		  return;
		  }
	   if(n==0)
	   {
	   	head=x;
	   	q=x;
	   }
		else 
	   {
	   	q->next=x;
	    q=x;
	   }
	    printf("%d %d %d\n",x->a,x->b,x->c);
	   Sleep(3000);
	   n++;
	  	
	  }
}

int main()
{  
  
  int Q=4;
  Begain();
  printf("%d\n",n);//用来判断有几组数据 
  Sleep(2000);
  
  while(Q)
  {
  	int N=Register();
  if(N==1)
  {
  	printf("生成账号成功！\n");
  }
  Save();
  Q--;
  }
  
 return 0;

}
