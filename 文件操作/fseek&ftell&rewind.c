#include<stdio.h>
int main ()
{
	FILE*p = fopen("test.txt","w");
	
	fputs("abcdef",p);
	fclose(p);
	p = NULL;
	
	FILE*p1 = fopen("test.txt","r");
	
		//��λ�ļ�ָ�� 
	fseek(p1,2,SEEK_SET);     // ��һ���������ļ�ָ��  ��Ϊƫ����  ��Ϊ���ļ�ָ���λ�� 
	
	//SEEK_CUR  �ļ�ָ��ĵ�ǰλ��
	//SEEK_END  �ļ���ĩβλ��
	//SEEK_SET   �ļ���ʼλ�� 
	
    int ch =fgetc(p1);  
	printf("%c\n",ch);//c
	
	//ftell  �ļ�ָ���������ʼλ�õ�ƫ����
	int a =ftell(p1);
	printf("%d\n",a);
	
	//rewind  ���ļ�ָ���λ�ûص���ʼλ��
	 rewind(p1);
	  ch =fgetc(p1);
	  printf("%c\n",ch);
	  
	fclose(p1);
	p = NULL;
	return 0;
 } 
