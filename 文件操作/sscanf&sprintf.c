#include<stdio.h>
struct S
{
	int n;
	float m;
	char arr[10];
};
int main()
{
    struct S s= {10,3.14,"abc"};
	char data[20] = {0};
	struct S tmp ={0};
	
	//�Ѹ�ʽ��������ת�����ַ������浽data��ȥ 
	sprintf(data,"%d %.2f %s",s.n,s.m,s.arr);
	printf("%s",data);	
	
	//��data�ж�ȡ��ʽ�������ݵ�tmp�� 
	sscanf(data,"%d %f %s",&(tmp.n),&(tmp.m),tmp.arr); 
	printf("%d %.2f %s",tmp.n,tmp.m,tmp.arr);
	
	return 0;
 } 
