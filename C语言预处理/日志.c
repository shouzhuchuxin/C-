#include<stdio.h>
int main()
{
	//__FILE__   ���б����Դ�ļ� 
	//__LINE__   �ļ���ǰ���к� 
	//__DATE__   �ļ������������ 
	//__TIME__    �ļ��������ʱ��
	//__STDC__    ��ѭC����ʱ����ֵΪ 1������δ���� 
	
	
	//дһ����������־�ĳ���
	
	//  ��һЩ����ʱ����Ϣ���浽�ļ���
	 
	FILE* p =fopen("bbb.txt","w");
	int i=0;
	int arr[10] ={0};
	for(i=0;i<10;i++)
	{
		arr[i] = i;
		fprintf(p,"flie = %s day = %s time = %s i = %d \n",
		__FILE__,__DATE__,__TIME__,i);
	 } 
	fclose(p);
	p =NULL;
	
	
	
	
	return 0;
 } 
