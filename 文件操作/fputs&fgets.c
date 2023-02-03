#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* p1 =fopen("text.txt","w");
	if(p1 == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	//  写文件 
	fputs("hello\n",p1);   // 输出一行 输出到文件中 
	fputs("world",p1);
	
	fclose(p1);
	p1 = NULL;
	//  读文件
	char arr[1024] = { 0 };
	FILE*p2 = fopen("text.txt","r");
	if(p2 == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	
	fgets(arr,1024,p2); //  从文件中读取 存放到arr中 1024代表读取的最大数 
	   printf("%s\n",arr);      // 只读取一行  并且会将 \n 读取 
	 puts(arr); //puts 不仅会读取 \n 它本身还会直接自动添加 \n  
	   
	fgets(arr,1024,p2);				    
	printf("%s",arr); 
	
	puts(arr); 
	 
	fclose(p1);
	p1 = NULL;
	
	
	//从键盘读取一行文本信息
	char data[1025] = { 0 };
	fgets(data,1025,stdin);
	fputs(data,stdout);
	
	//等价于 ： gets() puts()
	 
	return 0;
}
