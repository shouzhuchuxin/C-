#include<stdio.h>
#include<assert.h>
//��һ�����־��󣬾����ÿ�д����Ҷ��ǵ����ģ�ÿ�д��ϵ��¶��ǵ�����
//��д���������������Ѱ��ĳ�������Ƿ����
//Ҫ��ʱ�临�Ӷ�С��O��N��  ��Ѱ�Ҵ���С��N=9�� 
int xunzhao(int (*p)[3],int k,int *l,int *r)
{
	assert(p);
	int x =0;//�� 
	int y =*r-1;//��
	
	while(y>=0 && x<=*r-1)
	{
		if((*(*(p+x))+y) > k)
	
	    y--;
	
	else if((*(*(p+x))+y) < k)
	
	    x++; 
	else 
	{
		*l=x;
		*r=y;
		return 1;
	}
	    
		}	
	return 0;	
 } 
int main()
{
	int arr[3][3] ={{1,2,3},{4,5,6},{7,8,9}};
	int k=0;
	printf("������ҪѰ�ҵ�������\n");
	scanf("%d",&k);
	int x=3;
	int y=3;
	int i= xunzhao(arr,k,&x,&y);
	if(i==1)
	{
		printf("�ҵ��ˡ�\n");
		printf("���±�Ϊ��%d��%d\n",x,y);
	}
	else
	printf("�����ڡ�\n");
	
	return 0;
 } 
