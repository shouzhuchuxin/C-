#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	//向内存申请 10 个整形空间 
	int * p =(int*)malloc(10*sizeof(int));
	
	if(p == NULL)
	{
		//打印申请错误的原因 
		printf("%s\n",strerror(errno));
	}
	else 
	{
		//正常使用
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
	//每次申请空间后，当不使用它时要将它回收， 并指向空指针 
	free(p);
	p=NULL; 
	
	return 0;
 } 
