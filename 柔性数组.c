#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
void test()
{
	 //�������Ƶķ���   û������ĺ� 
 struct C
 {
 	
 	int m;
 	int*p;
  } ;
  // ע��������malloc��ʹ�� 
  struct C*z1 = (struct C*)malloc(sizeof(struct C));
  z1->p=(int*)malloc(sizeof(int)*5);
  //����ʹ��malloc�ڶ����Ͽ���һ���ṹ��Ŀռ䲢ʹ z1 ָ��ÿռ�ĵ�ַ
  // Ȼ���ٴ�ʹ��mallocΪ�ṹ���е�ָ��p ����һ�� ��int*�����͵Ŀռ� 
   // ���ݿ��ٵĿռ����ڴ��в�������
    
  int i=0;
  for(i=0;i<5;i++)
  {
  	z1->p[i]=i;
  }
  for(i=0;i<5;i++)
  {
  	printf("%d",z1->p[i]); 
  }
  //������С
  int*z2 = (int*)realloc(z1->p,sizeof(int)*10);// �ı�ָ��p ��ָ��ռ�Ĵ�С 
  if(z2 != NULL)
  {
  	z1->p = z2;
  }
  for(i=5;i<10;i++)
  {
  	z1->p[i] = i;
  }
  for(i=0;i<10;i++)
  {
  	printf("%d",z1->p[i]);
  }
  //�ͷ��ڴ�  ע���ͷŵ�˳�� 
  free(z1->p);
  z1->p=NULL;
  free(z1);
  z1=NULL;
   
}
int main()
{
	struct S
	{
		int n;
		int arr[0];//δ֪��С�� - ���������Ա  - ����Ĵ�С�ɵ��� 
	}s; //   ����дΪ�� int arr [] 
	
	printf("%d\n",sizeof(s)); //4  ���������ʱ��ռ�ڴ�
	
	struct S*p1 = (struct S*)malloc(sizeof(struct S ) + sizeof(int) * 5);
	//���ٵĿռ����ڴ����������� �Ӻź����������Ŀռ� 
	
	if(p1 == NULL)
	{
		printf("%s\n",errno);
		return 0;
	 } 
	 p1 ->n =100;
	 int i=0;
	 for(i= 0 ;i < 5;i++ )
	 {
	 	p1->arr[i]=i;
	 }
	 for(i = 0;i < 5;i++)
	 {
	 	printf("%d\n",p1->arr[i]);

	 }
	 //���ӽṹ������������Ĵ�С
	 struct S* p2 = (struct S*)realloc(p1,sizeof(int)*10);
	 if(p2!=NULL)
	 {
	 	p1=p2;
	  } 
	  for(i=5;i<10;i++)
	  {
	  	p1->arr[i] = i;
	  }
	  for(i=10;i<10;i++)
	  {
	  	printf("%d\n",p1->arr[i]);
	  }
	 free(p1);
	 p1=NULL;
	 
	 test();
	return 0;
 } 
 
 
  
  
  
  
  
