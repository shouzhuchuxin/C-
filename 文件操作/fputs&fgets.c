#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* p1 =fopen("text.txt","w");
	if(p1 == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	//  д�ļ� 
	fputs("hello\n",p1);   // ���һ�� ������ļ��� 
	fputs("world",p1);
	
	fclose(p1);
	p1 = NULL;
	//  ���ļ�
	char arr[1024] = { 0 };
	FILE*p2 = fopen("text.txt","r");
	if(p2 == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	
	fgets(arr,1024,p2); //  ���ļ��ж�ȡ ��ŵ�arr�� 1024�����ȡ������� 
	   printf("%s\n",arr);      // ֻ��ȡһ��  ���һὫ \n ��ȡ 
	 puts(arr); //puts �������ȡ \n ��������ֱ���Զ���� \n  
	   
	fgets(arr,1024,p2);				    
	printf("%s",arr); 
	
	puts(arr); 
	 
	fclose(p1);
	p1 = NULL;
	
	
	//�Ӽ��̶�ȡһ���ı���Ϣ
	char data[1025] = { 0 };
	fgets(data,1025,stdin);
	fputs(data,stdout);
	
	//�ȼ��� �� gets() puts()
	 
	return 0;
}
