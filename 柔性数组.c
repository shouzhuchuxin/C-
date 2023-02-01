#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
void test()
{
	 //另种相似的方法   没有下面的好 
 struct C
 {
 	
 	int m;
 	int*p;
  } ;
  // 注意这两次malloc的使用 
  struct C*z1 = (struct C*)malloc(sizeof(struct C));
  z1->p=(int*)malloc(sizeof(int)*5);
  //首先使用malloc在堆区上开辟一个结构体的空间并使 z1 指向该空间的地址
  // 然后再次使用malloc为结构体中的指针p 开辟一个 （int*）类型的空间 
   // 两份开辟的空间在内存中并不连续
    
  int i=0;
  for(i=0;i<5;i++)
  {
  	z1->p[i]=i;
  }
  for(i=0;i<5;i++)
  {
  	printf("%d",z1->p[i]); 
  }
  //调整大小
  int*z2 = (int*)realloc(z1->p,sizeof(int)*10);// 改变指针p 所指向空间的大小 
  if(z2 != NULL)
  {
  	z1->p = z2;
  }
  for(i=5;i<10;i++)
  {
  	z1->p[i] = i;
  }
  for(i=0;i<10;i++)
  {
  	printf("%d",z1->p[i]);
  }
  //释放内存  注意释放的顺序 
  free(z1->p);
  z1->p=NULL;
  free(z1);
  z1=NULL;
   
}
int main()
{
	struct S
	{
		int n;
		int arr[0];//未知大小的 - 柔性数组成员  - 数组的大小可调整 
	}s; //   还可写为： int arr [] 
	
	printf("%d\n",sizeof(s)); //4  柔性数组此时不占内存
	
	struct S*p1 = (struct S*)malloc(sizeof(struct S ) + sizeof(int) * 5);
	//开辟的空间在内存中是连续的 加号后面的是数组的空间 
	
	if(p1 == NULL)
	{
		printf("%s\n",errno);
		return 0;
	 } 
	 p1 ->n =100;
	 int i=0;
	 for(i= 0 ;i < 5;i++ )
	 {
	 	p1->arr[i]=i;
	 }
	 for(i = 0;i < 5;i++)
	 {
	 	printf("%d\n",p1->arr[i]);

	 }
	 //增加结构体中柔性数组的大小
	 struct S* p2 = (struct S*)realloc(p1,sizeof(int)*10);
	 if(p2!=NULL)
	 {
	 	p1=p2;
	  } 
	  for(i=5;i<10;i++)
	  {
	  	p1->arr[i] = i;
	  }
	  for(i=10;i<10;i++)
	  {
	  	printf("%d\n",p1->arr[i]);
	  }
	 free(p1);
	 p1=NULL;
	 
	 test();
	return 0;
 } 
 
 
  
  
  
  
  
