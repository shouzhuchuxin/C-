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
	z*head = NULL;  //head��ͷ�ڵ� 
	   z*q = NULL;  //��q����ʾÿ��������������һ����λ���Է����������һ����������� 
	   
	   void goto_xy(int x, int y) 
{
	HANDLE hout; 
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };  
	SetConsoleCursorPosition(hout, pos);  
}


//�� Register���������˺ź����룬��Save�������䱣�����ļ���
//Ȼ������һ�����иó���ʱ���ļ��е�����ֱ�ӷŵ�������
//�����ǣ����ļ�������������ʱ��ͨ��n��ʾֻ��һ�����ݵõ��˴�� 

int Register()
{

	z*p=NULL;
	while(1)
	{
	system("cls");
	goto_xy(12,2);
	printf("��������ɵ��˺�Ϊ��\n");
		
	srand((unsigned)time(NULL));
	
	 		 
	//ͨ�����������ɵ����� 
   p=(z*)malloc(sizeof(z));
   if(p==NULL)
    {
    		printf("%s\n",strerror(errno));
	}
	
	p->a=100000+ rand()%900000;
	//��һ������ʱҪ��head��ָ��ͷ�ڵ� 
	if(n == 0)
	{
		head = p;
		q=p;
	
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
	 
	 p->next=NULL;
	 p->c=0;
	 
	 if(n!=0)//�Ժ�����ʱֻ��Ҫq��ָ�������ɵ�����λ�� 
	 {
	 	q->next=p;
	 	q=p;
		 
	 }
	 n++;
	 count++;
	 return 1;
	
		}
	
}	

//�����ݱ������ļ��� 
void Save()
{
	int number=0;
	z*v=NULL;
	FILE*p=fopen("text.txt","w");
	 if(p==NULL)
	 printf("���������޷����棡\n");
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
		 	printf("����ɹ���\n");
		 	Sleep(2000);
		 	p=NULL;
			 return ;
		 }
		 
	 }
	 
 } 
 
 //���г���ʱ���ļ��е����ݱ����������У�ÿ�����ݶ���Ҫͨ���¿��ٵ�����������
 //���ҵ�ʹ��Register���������µ�����ʱ�ܽ�������Begain�������ɵ������������� 
 
 //��Ҫ�����Begain���������⣬������ 
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
	  	printf("����ɹ���"); 
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
  printf("%d\n",n);//�����ж��м������� 
  Sleep(2000);
  
  while(Q)
  {
  	int N=Register();
  if(N==1)
  {
  	printf("�����˺ųɹ���\n");
  }
  Save();
  Q--;
  }
  
 return 0;

}
