#include<stdio.h>
#include<assert.h>
char* my_strstr(const char*p1,const char*p2)//查找子串的函数 
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	char*s1=NULL;
	char*s2=NULL;
	char*cat=(char*)p1; // p1的类型为const char*需强制类型转换为char* 
	while(*cat)
	{
	    s1=cat;
		s2=(char*)p2;
		
		if(p2 == '\0')
		{
			return (char*)p1;
		}
		
		while(*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return cat;
		}
		if(*s1 == '\0')
		{
			return NULL;
		}
		cat++;
	}
}
int main()
{
	char*p1="abbbcdef";
	char*p2="bcd";
	char*ret = my_strstr(p1,p2);
	if(ret == NULL)
	printf("不存在子串。\n");
	else 
	printf("%s",ret);
	return 0;
}
//整体思路为：
//1.设置指针s1、s2、act
//           s1 s2 先设为空指针   act指向p1
//2.设置一个while循环条件为*act！=0
//  在这个while循环中，首先令s1=act  s2=p2 
// 然后进入一个while循环，此while用来判断两个字符是否相等
// 如果不相等 跳出循环，act地址加一 在进行最开始的while循环 
// 而在这次的while循环中，act地址已经加一 s1的指向也发生改变 s2未改变   
