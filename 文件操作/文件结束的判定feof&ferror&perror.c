#include<stdio.h>
#include<string.h>
int main()
{       
            // feof  �����û�н�������ֵ��  0�� 
         //Ӧ���ڵ��ļ���ȡ����ʱ���ж��Ƕ�ȡʧ�ܽ��������������ļ���β���� 
	//feof()  // EOF - emd of file -�ļ�������־
    FILE* p =fopen("test.txt","r");
	if(p == NULL)
	{
		perror("hehe");  //������strerror(errno)   
		               //��������ǣ�����������ַ�������ֱ�������������� 
		return 0;
		}	
	 
	 int ch = 0;
	 while((ch = fgetc(p)) != EOF)
	 {
	 	putchar(ch);
	 }
	 
	 printf("\n");
	 
	 //��ȡ�����½��� 
	 if(ferror(p))    //   ferror �����ж��ļ�ָ�� 
	 {
	 	printf("error\n");
	 }
	 
	 //������ȡ����   ����ֵ�ǲ�Ϊ  0  ���� 
	 else if(feof(p))
	 {
	 	printf("end of file\n");
	 }
	 
	  
	 fclose(p);
	 p= NULL;
	return 0;
 } 

