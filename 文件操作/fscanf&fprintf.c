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
	//格式化的形式写文件
	 
	fprintf(p,"%d %f %s",s.n,s.b,s.arr);  //把数据输出到文件中 
	
	//关闭文件 
	fclose(p);
	p= NULL;
	
	FILE* p1 =fopen("test.txt","r");
	if(p1 == NULL)
	{
		return 0;
	 } 
	
	//格式化的输入数据 
	fscanf(p1,"%d%f%s",&(s.n),&(s.b),s.arr); //把文件中的数据读取出来 
	printf("%d %.2f %s",s.n,s.b,s.arr);
	
	// 使用键盘和屏幕进行输入/输出
	fscanf(stdin,"%d %f %s",&(s.n),&(s.b),s.arr);
	fprintf(stdout,"%d %.2f %s",s.n,s.b,s.arr);
	
	 
	fclose(p1);
	p1 = NULL;
	return 0;
 } 
