#include<stdio.h>
#include<string.h>
struct S5
	 {
        int a;
		char n[20];
		double c;	 
	 }s5;
	 
void Print( struct S5 *p)
{
	printf("%d %s %1f\n",p->a,p->n,p->c);
}

int main()
{
	typedef struct S
	{
		int a;
		char b;
		int c;
		struct S*p;  //可能是用来进行链式访问的，具体咋用有待探讨 
	}s;            // 使用typedef后s即为struct S类型可以用s来定义变量 
	
	struct 
	{
		int a;
		char b;
	}a;   //struct后可不跟名字，但只能在开始定义的地方定义变量
	     //每个这样的结构体编译器都默认不一样
		  
	//内存对齐：详见手机 主要是寻找对齐数  从而确定倍数 以确定储存的字节数
	
	struct S1
	{
		char a;
		int b;
		char c;
	 }s1;
	 
	 struct S2
	 {
	 	char a;
	 	char b;
	 	int c;
	  } s2;
	  
	  struct S3
	  {
	  	char a;
	  	int b;
	  	struct S2 s2;
	  	
	  }s3;
	  printf("%d\n",sizeof(s1));//12
	  printf("%d\n",sizeof(s2));//8
	  printf("%d\n",sizeof(s3));//16
	
	
	//设置默认对齐数位4  此编译器应该是8
	#pragma pack(4)
	struct S4
	{
		char c; //1
		//7
		double a;//8
	 } s4;
	 
	 //取消默认对齐数 
	 #pragma pack()
	 
	 printf("%d\n",sizeof(s4));//本来应该为16   设置默认对齐数为4后变为12 
	 
	 
	 
	 
	 //struct S5 s5={ 10 , "李四",3.14};     可行！！！！！ 
	 s5.a=10;
	 //s5.n="张三";    // 不可行！！！！ 
	                  //此时的数组名表示的是一个指针，指向数组的首元素地址，这样赋值就等于尝试修改地址 
	 s5.c=3.14; 
	 
	 char m[] = {"张三"};   // 这个可行！！！！！ 
	 //strcpy(s5.n,m);   or
	 strcpy(s5.n,"张三");
	 
	 void Print(struct S5*p);
	 Print(&s5);                 //传址效率更高 
	return 0; 
 } 
 
