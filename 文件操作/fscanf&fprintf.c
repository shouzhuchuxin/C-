#include<stdio.h>
#include<string.h>
#include<errno.h>
struct S
{
	int n;
	float b;
	char arr[10];
	
};
int main()
{
	struct S s ={10 ,3.14f,"abcdef"};
	FILE* p =fopen("test.txt","w");
	if(p== NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	//��ʽ������ʽд�ļ�
	 
	fprintf(p,"%d %f %s",s.n,s.b,s.arr);  //������������ļ��� 
	
	//�ر��ļ� 
	fclose(p);
	p= NULL;
	
	FILE* p1 =fopen("test.txt","r");
	if(p1 == NULL)
	{
		return 0;
	 } 
	
	//��ʽ������������ 
	fscanf(p1,"%d%f%s",&(s.n),&(s.b),s.arr); //���ļ��е����ݶ�ȡ���� 
	printf("%d %.2f %s",s.n,s.b,s.arr);
	
	// ʹ�ü��̺���Ļ��������/���
	fscanf(stdin,"%d %f %s",&(s.n),&(s.b),s.arr);
	fprintf(stdout,"%d %.2f %s",s.n,s.b,s.arr);
	
	 
	fclose(p1);
	p1 = NULL;
	return 0;
 } 
