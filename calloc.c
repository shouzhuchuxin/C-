#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	int *p =(int*)calloc(10,sizeof(int));
	if(p == NULL)
	{
		printf("%s\n",strerror(errno));
	}
	//对空间进行初始化 并且赋值0
	int i=0;
	for(i=0;i<10;i++)
	
	{
		printf("%d",*(p+i));  // 0000000000
	}
	free(p);
	p=NULL;
	
	return 0;
}
