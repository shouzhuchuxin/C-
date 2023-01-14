#include<stdio.h>
#include<assert.h>
void* my_memmove(void*p1,const void*p2,size_t count)
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	
	char *ret =p1;
	if(p1<p2)                   //通过p1 p2 地址的先后顺序选择不同的交换方法 
	{
		while(count--)         // 从前->后 
		{
			*(char*)p1 = *(char*)p2;
			(char*)p1++;
			(char*)p2++;
		}
	}
	else 
	{
		while(count--)          // 从后-> 前 
		{
			*((char*)p1 + count ) = *((char*)p2 + count ) ;
		}
	}
	return ret;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	my_memmove(a,a+2,20);  // 从a+2地址处开始的20个字节拷贝到a开始的地址处 
	int i=0;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	printf("%d",a[i]); 
	
	//    memset  内存设置:
	 char arr[10] = {0};
	 memset(arr,'#',10);   //  '#'为在一个字节的地址中存放的东西   10 为存放的字节数 
    // 错误用法：
	int arr1[10] = {0};
	  //memset(arr1,1,10);  //  该数组为int 类型 占40个字节 只存放10个字节的1是错误的 
	return 0;
}
