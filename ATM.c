#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<errno.h> 
#include<time.h>

//���ȴ����Ľṹ�壬����ı��岿�֣������������ݺ͵�ַ 
typedef struct User
{
   int a;
   int b;
   int Money;
   	struct User*next;
}user;

int Name=0;//�����Ϊ�˴�ŵ�¼���˺ţ��Ա���жԸ��˺������ݵĲ�������½�������丳ֵ�� 

int i=0;
int n=0; //����Ϊ�˴��������ʱ��ʹheadָ���һ��λ�ã���ȡ�ļ�ʱҲҪ�õ� 
int count=0; //���������ʾ�˻��ĸ��� 
	struct User*head = NULL; //ͷ�ڵ� 
	   struct User*q = NULL; //���һֱָ����������һ��λ�ã������������� 
//����ƶ�����
 
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
	if(MessageBox(NULL,TEXT("  ȷ���˳���"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK) 
		 	{
		 		printf("\n\n          ллʹ�ã�\n");
		 		free(head);
		 		return ;
			 }*/
			 
			 int n,m;
			 goto_xy(20,10);
			 printf("ȷ���˳���");
			 goto_xy(20,11);
			 printf("1.��ȷ����2.��ȡ����");
			 goto_xy(20,12);
			 scanf("%d",&m);
			if(m==1)
			 	return 0;
			else if(m==2)
				return 1;
			
}

//ͨ�����������˻����в���	�����ص��Ǹò����������ĵ�ַ���Ա��ڶԵ�ַ�е����ݽ��и��� 
user* Find(int m)
{
		struct User*P=head;
		int j=0;
	
			for(j=0;j<count;j++)//!!!!!!!!��ʱcount�������ó� 
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

	//�˺����ɺ�����������һ��������˺ţ��������ʱ��Ϊ���� ������λ�� 
int Register()
{

	struct User*p;

	while(1)
	{
	system("cls");
	goto_xy(12,2);
	printf("��������ɵ��˺�Ϊ��\n");
		
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
	 
	 
	 printf("������һ����λ�������롣\n");
	 while(1)
	 {
	 	scanf("%d",&(p->b));
	 	if(!((p->b>=100000)&&(p->b<=999999)))
	 		printf("����λ�����ڻ�С����λ�����������룡\n");
	 	else
	 		break;
	 }
	 //���������������� 
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
//��¼���� 
int Ender()
{
	 int i=0,j=0,x,y,Num=0; 
	printf("�������˺ţ�\n");
	scanf("%d",&i);
	user*Q=Find(i);
	if(Q!=NULL) ;
	else 
		return 0;
		while(1)
		{
				printf("���������룺\n");
				scanf("%d",&j);
				if(Q->b==j)
				{
					Name=i;
					return 1;
				}
					
				else 
				{
							printf("��������������������룡"); 
							Num++;
				}
				if(Num==3)
				{
					printf("������󳬹����Σ������µ�½��\n");
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
	printf("*      ��ѡ�����¹��ܣ�  *\n");
	printf("*       1.�޸�����       *\n");
	printf("*       2.��ѯ���       *\n");
	printf("*       3.ȡ��           *\n");
	printf("*       4.ʵʱ���       *\n");
	printf("*       5.�˳�           *\n");
	printf("**************************\n");
}

void menu2()
{
	printf("****************************\n");
	printf("*                          *\n");
	printf("*      ��ӭʹ�ø�ATM��     *\n");
	printf("*        �����뿨��        *\n");
	printf("*                          *\n");
	printf("*          1.ȡ��          *\n");
	printf("*          2.��¼          *\n");
    printf("*          3.ע��          *\n");
	printf("****************************\n");
}

void Save()
{
	int number=0;
	user*z=NULL;
	FILE*p=fopen("text.txt","w");
	 if(p==NULL)
	 printf("���������޷����棡\n");
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
    //����ط��Լ�Ҳ��ʱ�㲻�����ˣ���Ҫ���ÿ��ˣ��Ժ�ǵÿ��������������������� 
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
			default:printf("����������������룡\n");
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
			printf("��½�ɹ���\n");
			Sleep(1000);
			return y;
		 } 
		 else if(y!=1&&j==2)
		 {
		 		printf("�˺Ż������������\n");
		 		Sleep(1000);
		 }
		 	if(x==1&&j==3)
		{
			printf("ע��ɹ���\n");
			Save();
			Sleep(1000);
		}	
		else if(x!=1&&j==3)
		{
				printf("ע��ʧ�ܣ�������ѡ��\n"); 
				Sleep(1000);
		}
	}
	
}

void Check_Balance()
{
	user*p=Find(Name);
	    printf("�����˻����Ϊ��%d\n",p->Money);
	    Sleep(3500);
}

int Chage_Password()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("������Ҫ���ĵ����룺\n");
	while(1)
	{
			scanf("%d",&Pass);
			if(Pass<100000||Pass>999999);
			else 
			{
				p->b=Pass;	
					printf("�޸ĳɹ��������µ�½��\n");
					Sleep(2000);
					return x=1;
			}
	
	}

}

void Withdraw_Money()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("������Ҫȡ�Ľ�\n");
	while(1)
	{
		scanf("%d",&x);
	if(x>(p->Money))
	{
		printf("���㣡������ѡ���\n");
	}
	else 
	{
		p->Money-=x;
		printf("ȡ��ɹ���\n");
		Sleep(2000);
		return ; 
	}
	
	}
}

void Real_Time_deposits()
{
	int Pass=0,x=0;
	user*p=Find(Name);
	printf("������Ҫ��ȡ�ý�\n");
	scanf("%d",&x);
	p->Money+=x;
	printf("���ɹ���\n");
	Sleep(2000);
}

//���ļ�����д���������v���ж϶��ļ��Ƿ��ȡ��ϣ�
//�������������ݣ�����е��������ݶ�ȡ��Ϻ�v����ΪNULL�������Ĵν��ж�ȡʱ��ΪNULL
//���ԣ�Ӧע���жϽ�������λ�� 
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
		  //��һ�ζ�ȡʹͷ�ڵ�ָ���һ��λ�� 
	   if(n==0)
	   {
	   	head=x;
	   	q=x;
	   }
	   //�Ժ�Ķ�ȡ����Ϊ���������� 
		else 
	   {
	   	q->next=x;
	    q=x;
	   }
	   n++;
	  	count++; //����ط��ǵü��ϣ������Ĳ���ʱ�����Ҵ�����Ϊ0��ʹ���޷���¼ 
	  }
}


int main()
{
	int a=1;
    int b=1;

	Begain();	
	while(1)
	{
		//Welcome�����ķ���ֵ���ж��Ƿ��˳����� 
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
		case 1:x=Chage_Password();//�޸����� 
			break;
		case 2:Check_Balance();//��ѯ��� 
			break;
		case 3:Withdraw_Money();//ȡ�� 
			break;
		case 4:Real_Time_deposits();//ʵʱ���
			break;
		case 5:b=Exit();//�˳�
			break;
		default:printf("����������������룡\n");
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
