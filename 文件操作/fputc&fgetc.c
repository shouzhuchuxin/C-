#include<stdio.h>
#include<string.h>
#include<errno.h>
int main ()
{
	//���ļ�test.txt
	//���·��
	//.. ��ʾ��һ��·��
	//.  ��ʾ��ǰ·��
	//fopen("..\..\text.txt","r")
	//fopen("text.txt","r")
	
	//����·����д��
	//fopen("C:\\Users\\86195\\Desktop\\C\\�ļ�����\\text.txt","r") 
	//��ӵ�һ�� \ ��ֹ�ַ���ת��
	
	 //  FILE(�ļ�ָ��) �������һ�ֽṹ������  ÿ�δ��ļ������б仯 ����ϵͳ���Զ��ı� 
	FILE* p =fopen("test.txt","w");  // ��ֻдʱԭ�ļ��е����ݻᱻɾ�� 
	//�����ʧ����᷵�ؿ�ָ�� ������Ҫ�ж�
	
	if(p == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	 } 
	 //�򿪳ɹ�
	 //���ļ�
	 //�ر��ļ�
	 fclose(p);
	 p = NULL;
	  
	 // --------------------------
	  
	 FILE*p1 = fopen("text1.txt","w");
	 if( p1 == NULL)
	 {
	 	printf("%s\n",strerror(errno));
	 	return 0;
	  } 
	
	//д�ļ�
	fputc('b',p1);
	fputc('i',p1);
	fputc('t',p1);
	
	//�ر��ļ�
	fclose(p1);
	p1 = NULL; 
	
	//-------------------------------
	
	 FILE*p2 = fopen("text1.txt","r");
	 if( p2 == NULL)
	 {
	 	printf("%s\n",strerror(errno));
	 	return 0;
	  } 
	
	//���ļ�
	printf("%c",fgetc(p2));//b
	printf("%c",fgetc(p2));//i
	printf("%c",fgetc(p2));//t

	//�ر��ļ�
	fclose(p2);
	p2 = NULL; 
	
	//-------------------------------
	
	//�Ӽ�������
	//����Ļ���
	//����&��Ļ�����ⲿ�豸
	
	
	//���� - ��׼�����豸 - stdin
	
	//��Ļ - ��׼����豸 - stdout 
	
	//��һ������Ĭ�ϴ򿪵��������豸 

    //stdin FILE*
	//stdout FILE*
	//stderr FILE* 
	
	int c = fgetc(stdin); //fgetc�ӱ�׼������(����)�ж�����Ϣ - ��ֵ��c 
	fputc(c,stdout); //  �� c �е����ݴӱ�׼�����(��Ļ)����� 
	
	
	return 0;
}
