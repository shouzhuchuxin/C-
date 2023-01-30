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
	int i=0;
	for(i=0;i<10;i++)
	
	{
		printf("%d",*(p+i));
	}
	free(p);
	p=NULL;
	
	return 0;
}
