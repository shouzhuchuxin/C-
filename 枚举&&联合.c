#include<stdio.h>
int pandaun ()
{
	union H
	{
		int i;
		char b;
	}h;
	h.i=1;          // ���ǵ�ַ��ʼ�ĵط���ͬ������charֻ����һ���ֽ� 
	return h.b;
}
int main()
{
	//ö�٣�   enum�Ĵ�СΪ  4 ���ֽ�  �﷨ֱ�Ӷ��� 
	enum sex
	{
		MAN,   //0
		WOMAN,  // 1
		heihei   // 2
		
	}e;
	enum color
	{
		red = 4,  // 4
		green ,   // 5
		blue= 6   // 6
	}c;
	
	int color_1 = red; // 4
	
		printf("%d %d %d\n",MAN,WOMAN,heihei);
	printf("%d %d %d\n",red,green,blue);
	printf("%d\n",color_1);
	
	printf("%d\n",sizeof(c)); // ö�ٵĴ�СΪ 4  
	
	//���ϣ�
	        // ���ϵĴ�С����������Ա�Ĵ�С
			// ������Ա��С��������������������ʱ����Ҫ���뵽���������������� 
	 union un
	 {
	 	char a;
	 	int i;
	  }u; 
	  printf("%d\n",sizeof(u));//4
	  
	  printf("%p\n",&u);    // ���ǵĵ�ַ����ͬ 
	  printf("%p\n",&(u.a));
	  printf("%p\n",&(u.i));	
	  
	  int i=1;         //ʹ��ʱֻ��ʹ��һ�� 
	  //char a = 'w'; 
	  
	  //�жϴ�С�ˣ�
	  
	  int f =1;
	  if(*(char*)&f == 1)
	  {
	  	printf("С�ˡ�\n");
	  	
	   }
	   else 
	   printf("��ˡ�\n");
	   
	   //��������
	   int ret = pandaun() ;
	   if(ret == 1)
	  {
	  	printf("С�ˡ�\n");
	  	
	   }
	   else 
	   printf("��ˡ�\n");
	return 0;
}
