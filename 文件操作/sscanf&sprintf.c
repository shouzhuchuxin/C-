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
	
	//把格式化的数据转换成字符串储存到data中去 
	sprintf(data,"%d %.2f %s",s.n,s.m,s.arr);
	printf("%s",data);	
	
	//从data中读取格式化的数据到tmp中 
	sscanf(data,"%d %f %s",&(tmp.n),&(tmp.m),tmp.arr); 
	printf("%d %.2f %s",tmp.n,tmp.m,tmp.arr);
	
	return 0;
 } 
