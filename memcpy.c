#include<stdio.h>
#include<assert.h>
struct S
{
	char name[20]; //  注意此处[20]的用处 
	int age;
};
void * my_memcpy(void*p1, const void* p2,size_t a) //size_t代表无类型的整数 
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	
	void*ret = p1;
	while(a--)
	{
		*((char*)p1) = *((char*)p2);
	     (char*)p1++;
	     (char*)p2++;
	}
	return ret;       //返回的为空指针应该就可以 
}
int main()
{
   struct S s[]={{"张三",10},{"李四",20}};
   struct S a[3] ={0};
   my_memcpy(a,s,sizeof(s));  //最后一个参数为需要拷贝的字节数 
   int i=0;
   for(i=0;i<2;i++)
   {
   	  printf("%s\n%d\n",&(a[i].name),a[i].age);  //输出 字符串时 需要地址 
   }
	return 0;
}
