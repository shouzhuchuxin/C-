#include<stdio.h>
#include<string.h>
struct S5
	 {
        int a;
		char n[20];
		double c;	 
	 }s5;
	 
void Print( struct S5 *p)
{
	printf("%d %s %1f\n",p->a,p->n,p->c);
}

int main()
{
	typedef struct S
	{
		int a;
		char b;
		int c;
		struct S*p;  //����������������ʽ���ʵģ�����զ���д�̽�� 
	}s;            // ʹ��typedef��s��Ϊstruct S���Ϳ�����s��������� 
	
	struct 
	{
		int a;
		char b;
	}a;   //struct��ɲ������֣���ֻ���ڿ�ʼ����ĵط��������
	     //ÿ�������Ľṹ���������Ĭ�ϲ�һ��
		  
	//�ڴ���룺����ֻ� 
	
	struct S1
	{
		char a;
		int b;
		char c;
	 }s1;
	 
	 struct S2
	 {
	 	char a;
	 	char b;
	 	int c;
	  } s2;
	  
	  struct S3
	  {
	  	char a;
	  	int b;
	  	struct S2 s2;
	  	
	  }s3;
	  printf("%d\n",sizeof(s1));//12
	  printf("%d\n",sizeof(s2));//8
	  printf("%d\n",sizeof(s3));//16
	
	
	//����Ĭ�϶�����λ4  �˱�����Ӧ����8
	#pragma pack(4)
	struct S4
	{
		char c; //1
		//7
		double a;//8
	 } s4;
	 
	 //ȡ��Ĭ�϶����� 
	 #pragma pack()
	 
	 printf("%d\n",sizeof(s4));//����Ӧ��Ϊ16   ����Ĭ�϶�����Ϊ4���Ϊ12 
	 
	 
	 
	 
	 //struct S5 s5={ 10 , "����",3.14};     ���У��������� 
	 s5.a=10;
	 //s5.n="����";    // �����У������� 
	                  //��ʱ����������ʾ����һ��ָ�룬ָ���������Ԫ�ص�ַ��������ֵ�͵��ڳ����޸ĵ�ַ 
	 s5.c=3.14; 
	 
	 char m[] = {"����"};   // ������У��������� 
	 //strcpy(s5.n,m);   or
	 strcpy(s5.n,"����");
	 
	 void Print(struct S5*p);
	 Print(&s5);                 //��ַЧ�ʸ��� 
	return 0; 
 } 
 
