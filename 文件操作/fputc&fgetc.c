#include<stdio.h>
#include<string.h>
#include<errno.h>
int main ()
{
	//打开文件test.txt
	//相对路径
	//.. 表示上一级路径
	//.  表示当前路径
	//fopen("..\..\text.txt","r")
	//fopen("text.txt","r")
	
	//绝对路径的写法
	//fopen("C:\\Users\\86195\\Desktop\\C\\文件操作\\text.txt","r") 
	//多加的一个 \ 防止字符被转义
	
	 //  FILE(文件指针) 代表的是一种结构体类型  每次打开文件都会有变化 不过系统会自动改变 
	FILE* p =fopen("test.txt","w");  // 当只写时原文件中的内容会被删除 
	//如果打开失败则会返回空指针 所以需要判断
	
	if(p == NULL)
	{
		printf("%s\n",strerror(errno));
		return 0;
	 } 
	 //打开成功
	 //读文件
	 //关闭文件
	 fclose(p);
	 p = NULL;
	  
	 // --------------------------
	  
	 FILE*p1 = fopen("text1.txt","w");
	 if( p1 == NULL)
	 {
	 	printf("%s\n",strerror(errno));
	 	return 0;
	  } 
	
	//写文件
	fputc('b',p1);
	fputc('i',p1);
	fputc('t',p1);
	
	//关闭文件
	fclose(p1);
	p1 = NULL; 
	
	//-------------------------------
	
	 FILE*p2 = fopen("text1.txt","r");
	 if( p2 == NULL)
	 {
	 	printf("%s\n",strerror(errno));
	 	return 0;
	  } 
	
	//读文件
	printf("%c",fgetc(p2));//b
	printf("%c",fgetc(p2));//i
	printf("%c",fgetc(p2));//t

	//关闭文件
	fclose(p2);
	p2 = NULL; 
	
	//-------------------------------
	
	//从键盘输入
	//从屏幕输出
	//键盘&屏幕都是外部设备
	
	
	//键盘 - 标准输入设备 - stdin
	
	//屏幕 - 标准输出设备 - stdout 
	
	//是一个程序默认打开的两个流设备 

    //stdin FILE*
	//stdout FILE*
	//stderr FILE* 
	
	int c = fgetc(stdin); //fgetc从标准输入流(键盘)中读入信息 - 赋值给c 
	fputc(c,stdout); //  将 c 中的内容从标准输出流(屏幕)上输出 
	
	
	return 0;
}
