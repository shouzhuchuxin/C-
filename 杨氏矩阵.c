#include<stdio.h>
#include<assert.h>
//有一个数字矩阵，矩阵的每行从左到右都是递增的，每列从上到下都是递增的
//编写程序在这个矩阵中寻找某个数字是否存在
//要求：时间复杂度小于O（N）  即寻找次数小于N=9次 
int xunzhao(int (*p)[3],int k,int *l,int *r)
{
	assert(p);
	int x =0;//行 
	int y =*r-1;//列
	
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
	printf("请输入要寻找的整数。\n");
	scanf("%d",&k);
	int x=3;
	int y=3;
	int i= xunzhao(arr,k,&x,&y);
	if(i==1)
	{
		printf("找到了。\n");
		printf("其下标为：%d，%d\n",x,y);
	}
	else
	printf("不存在。\n");
	
	return 0;
 } 
