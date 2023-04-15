#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<errno.h> 
#include<time.h>

//首先创建的结构体，链表的本体部分，用来储存数据和地址 
typedef struct User
{
   int a;
   int b;
   int Money;
   	struct User*next;
}user;

int Name=0;//这个是为了存放登录的账号，以便进行对该账号内数据的操作（登陆函数对其赋值） 

int i=0;
int n=0; //这是为了创建链表的时候使head指向第一个位置，读取文件时也要用到 
int count=0; //这个用来表示账户的个数 
	struct User*head = NULL; //头节点 
	   struct User*q = NULL; //这个一直指向链表的最后一个位置，用来连接链表 
//光标移动函数
 
void goto_xy(int x, int y) 
{
	HANDLE hout; 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };  
	SetConsoleCursorPosition(hout, pos);  
}

int Exit()
{
	/*
	if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK) 
		 	{
		 		printf("\n\n          谢谢使用！\n");
		 		free(head);
		 		return ;
			 }*/
			 
			 int n,m;
			 goto_xy(20,10);
			 printf("确定退出？");
			 goto_xy(20,11);
			 printf("1.（确定）2.（取消）");
			 goto_xy(20,12);
			 scanf("%d",&m);
			if(m==1)
			 	return 0;
			else if(m==2)
				return 1;
			
}

//通过传进来的账户进行查找	，返回的是该参数（链表）的地址，以便于对地址中的内容进行更改 
user* Find(int m)
{
		struct User*P=head;
		int j=0;
	
			for(j=0;j<count;j++)//!!!!!!!!这时count派上了用场 
	    {
		if(j==0)
		{
			if(head->a==m)
				return head;
				
			else
				P=head->next;
		}
		else 
			{
			if(P->a==m)
				return P;
			else
				P=P->next;
			}
		}
		

	return NULL;
}

	//账号生成函数用来生成一个随机的账号，随机数以时间为种子 且是六位数 
int Register()
{

	struct User*p;

	while(1)
	{
	system("cls");
	goto_xy(12,2);
	printf("您随机生成的账号为：\n");
		
	srand((unsigned)time(NULL));
	
   p=(struct User*)malloc(sizeof(struct User));
   if(p==NULL)
    {
    		printf("%s\n",strerror(errno));
	}
	if(n == 0)
	{
		head = p;
		q=p;
	
	 } 
	 
	 while(1)
	 {
	 		 p->a=100000+ rand()%900000;
	 		if((Find(p->a)!=NULL)&&n!=0);
			 else 
			 	break; 
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
	 //这里进行链表的链接 
	 p->next=NULL;
	 p->Money=0;
	 if(n!=0)
	 {
	 	q->next=p;
	 	q=p;
		 
	 }
	 n++;
	 count++;
	 return 1;
	
		}
	
}	
//登录函数 
int Ender()
{
	 int i=0,j=0,x,y,Num=0; 
	printf("请输入账号：\n");
	scanf("%d",&i);
	user*Q=Find(i);
	if(Q!=NULL) ;
	else 
		return 0;
		while(1)
		{
				printf("请输入密码：\n");
				scanf("%d",&j);
				if(Q->b==j)
				{
					Name=i;
					return 1;
				}
					
				else 
				{
							printf("密码输入错误，请重新输入！"); 
							Num++;
				}
				if(Num==3)
				{
					printf("输入错误超过三次，请重新登陆！\n");
					return 0;
				}
		
		}

		
	
}

	
void menu1()
{
	Sleep(1000);
	system("cls"); 
	system("color 4E");
	printf("**************************\n");
	printf("*      请选择以下功能：  *\n");
	printf("*       1.修改密码       *\n");
	printf("*       2.查询余额       *\n");
	printf("*       3.取款           *\n");
	printf("*       4.实时存款       *\n");
	printf("*       5.退出           *\n");
	printf("**************************\n");
}

void menu2()
{
	printf("****************************\n");
	printf("*                          *\n");
	printf("*      欢迎使用该ATM机     *\n");
	printf("*        请输入卡号        *\n");
	printf("*                          *\n");
	printf("*          1.取消          *\n");
	printf("*          2.登录          *\n");
    printf("*          3.注册          *\n");
	printf("****************************\n");
}

void Save()
{
	int number=0;
	user*z=NULL;
	FILE*p=fopen("text.txt","w");
	 if(p==NULL)
	 printf("操作错误，无法保存！\n");
	 while(1)
	 {
	 	if(number==0)
	 	{
	 		fprintf(p,"%d %d %d\n",head->a,head->b,head->Money);
	 		z=head->next;
		 }
		 else if(number!=0)
		 {
		 	fprintf(p,"%d %d %d\n",z->a,z->b,z->Money);
	 		z=z->next;
		 }
		 number++;
		 if(z==NULL)
		 {
		 	fclose(p);
		 	p=NULL;
			 return ;
		 }
		 
	 }
	 
 } 
 
int  Welcome()
{
	int j=0,k=1,x=0,y=0;
	system("color 2F");

    int L=1;
    //这个地方自己也暂时搞不明白了，主要懒得看了，以后记得看！！！！！！！！！！ 
	while(!x||!y)
	{
		system("cls");
		menu2();
		scanf("%d",&j);
		switch(j)
		{
			case 1:L=Exit();
				break; ; 
			case 2:y=Ender();
				break;
			case 3:x=Register();
				break;
			default:printf("输入错误，请重新输入！\n");
				break;
		}
		if(L==0)
		{
			Save();
			return L;
		}
		else if(L == 1) ;
		if(y)
		{
			printf("登陆成功！\n");
			Sleep(1000);
			return y;
		 } 
		 else if(y!=1&&j==2)
		 {
		 		printf("账号或密码输入错误！\n");
		 		Sleep(1000);
		 }
		 	if(x==1&&j==3)
		{
			printf("注册成功！\n");
			Save();
			Sleep(1000);
		}	
		else if(x!=1&&j==3)
		{
				printf("注册失败！请重新选择！\n"); 
				Sleep(1000);
		}
	}
	
}

void Check_Balance()
{
	user*p=Find(Name);
	    printf("您的账户余额为：%d\n",p->Money);
	    Sleep(3500);
}

int Chage_Password()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("请输入要更改的密码：\n");
	while(1)
	{
			scanf("%d",&Pass);
			if(Pass<100000||Pass>999999);
			else 
			{
				p->b=Pass;	
					printf("修改成功！请重新登陆！\n");
					Sleep(2000);
					return x=1;
			}
	
	}

}

void Withdraw_Money()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("请输入要取的金额：\n");
	while(1)
	{
		scanf("%d",&x);
	if(x>(p->Money))
	{
		printf("余额不足！请重新选择金额！\n");
	}
	else 
	{
		p->Money-=x;
		printf("取款成功！\n");
		Sleep(2000);
		return ; 
	}
	
	}
}

void Real_Time_deposits()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("请输入要存取得金额：\n");
	scanf("%d",&x);
	p->Money+=x;
	printf("存款成功！\n");
	Sleep(2000);
}

//对文件进行写入操作，用v来判断对文件是否读取完毕，
//例如有三行数据，则进行第三行数据读取完毕后v并不为NULL，当第四次进行读取时才为NULL
//所以，应注意判断结束语句的位置 
void Begain()
{
	 	user*x=NULL;
 FILE*p=fopen("text.txt","r");
	while(1)
	{
	  
	   	x=(user*)malloc(sizeof(user));
	   int v=fscanf(p,"%d%d%d",&(x->a),&(x->b),&(x->Money));
	   
	
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
		  return;
		  } 
		  //第一次读取使头节点指向第一个位置 
	   if(n==0)
	   {
	   	head=x;
	   	q=x;
	   }
	   //以后的读取都是为了链接链表 
		else 
	   {
	   	q->next=x;
	    q=x;
	   }
	   n++;
	  	count++; //这个地方记得加上，否则尽心查找时，查找次数会为0，使得无法登录 
	  }
}


int main()
{
	int a=1;
    int b=1;

	Begain();	
	while(1)
	{
		//Welcome函数的返回值来判断是否退出程序 
	   a= Welcome();
	   if(a==0)
		   return 0;
	   	while(1)
		   {
		   	int x=0;
		menu1();
		    scanf("%d",&i);
		switch(i)
		{
		case 1:x=Chage_Password();//修改密码 
			break;
		case 2:Check_Balance();//查询余额 
			break;
		case 3:Withdraw_Money();//取款 
			break;
		case 4:Real_Time_deposits();//实时存款
			break;
		case 5:b=Exit();//退出
			break;
		default:printf("输入错误，请重新输入！\n");
			continue; 
		}
		if(b==0)
		{
			Save();
			return 0;
		}
		 if(x==1)
		 {
		 	Save();
		 	 break;
		 }
	
		   }
	}
	return 0;
}
