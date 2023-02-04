#include<stdio.h>
int main()
{
	//__FILE__   进行编译的源文件 
	//__LINE__   文件当前的行号 
	//__DATE__   文件被编译的日期 
	//__TIME__    文件被编译的时间
	//__STDC__    遵循C语言时，其值为 1，否则未定义 
	
	
	//写一个类似于日志的程序：
	
	//  将一些编译时的信息保存到文件中
	 
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
