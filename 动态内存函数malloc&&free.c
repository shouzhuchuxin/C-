#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	//���ڴ����� 10 �����οռ� 
	int * p =(int*)malloc(10*sizeof(int));
	
	if(p == NULL)
	{
		//��ӡ��������ԭ�� 
		printf("%s\n",strerror(errno));
	}
	else 
	{
		//����ʹ��
		int i =0;
		for(i=0;i<10;i++)
		{
			*(p+i) = i;
		 } 
		 for(i=0;i<10;i++)
		 {
		 	printf("%d",*(p+i));
		 }
	}
	//ÿ������ռ�󣬵���ʹ����ʱҪ�������գ� ��ָ���ָ�� 
	free(p);
	p=NULL; 
	
	return 0;
 } 
