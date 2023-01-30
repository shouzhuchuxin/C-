#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
//1. 注意当使用函数进行动态内存开辟时，如果开辟失败，则指针会被赋为NULL
// 因此需注意对空指针的解引用，使用函数后先进行判断是否为：NULL
// 2. 注意对动态开辟的内存的越界访问。 
// 3. 注意使用 free 函数时的对象 只能是动态开辟的内存空间 
int main()
{
	int *p =(int*)malloc(10*sizeof(int));
	if(p==NULL)
	{
		printf("%s",errno);
	}
	else
	{
		
	int i=0;
	for(i = 0;i<10;i++)
	{
		*(p+i) = i;
	}
	
	}
	//realloc使用的注意事项
	//1. 如果p指向的空间之后有足够大的内存空间可以追加，则直接追加，后返回p
	//2. 如果p指向的空间之后没有足够的内存空间可以追加，则realloc函数会重新找一个新的内存区域
	// 开辟一块满足需求的空间，并且把原来内存中的数据拷贝回来，释放旧的内存空间
	// 最后返回新开辟的内存空间的地址
	// 3. 得用一个新的变量来接受realloc函数的返回值
	//  
	int *p1=(int*)realloc(p,100);
	if(p1 != NULL)
	{
		p = p1;
		int j=0;
		for(j=0;j<10;j++)
		{
			printf("%d",*(p+j));
		}
	}
	else
	{
		return 0;
	}
	free(p); 
	return 0;
 } 
