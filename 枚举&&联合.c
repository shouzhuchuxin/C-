#include<stdio.h>
int pandaun ()
{
	union H
	{
		int i;
		char b;
	}h;
	h.i=1;          // 他们地址开始的地方相同，不过char只传回一个字节 
	return h.b;
}
int main()
{
	//枚举：   enum的大小为  4 个字节  语法直接定义 
	enum sex
	{
		MAN,   //0
		WOMAN,  // 1
		heihei   // 2
		
	}e;
	enum color
	{
		red = 4,  // 4
		green ,   // 5
		blue= 6   // 6
	}c;
	
	int color_1 = red; // 4
	
		printf("%d %d %d\n",MAN,WOMAN,heihei);
	printf("%d %d %d\n",red,green,blue);
	printf("%d\n",color_1);
	
	printf("%d\n",sizeof(c)); // 枚举的大小为 4  
	
	//联合：
	        // 联合的大小至少是最大成员的大小
			// 当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数的整倍数 
	 union un
	 {
	 	char a;
	 	int i;
	  }u; 
	  printf("%d\n",sizeof(u));//4
	  
	  printf("%p\n",&u);    // 他们的地址都相同 
	  printf("%p\n",&(u.a));
	  printf("%p\n",&(u.i));	
	  
	  int i=1;         //使用时只能使用一个 
	  //char a = 'w'; 
	  
	  //判断大小端：
	  
	  int f =1;
	  if(*(char*)&f == 1)
	  {
	  	printf("小端。\n");
	  	
	   }
	   else 
	   printf("大端。\n");
	   
	   //函数法：
	   int ret = pandaun() ;
	   if(ret == 1)
	  {
	  	printf("小端。\n");
	  	
	   }
	   else 
	   printf("大端。\n");
	return 0;
}
