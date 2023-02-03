#include<stdio.h>
#include<string.h>
int main()
{       
            // feof  （如果没有结束返回值是  0） 
         //应用于当文件读取结束时，判断是读取失败结束，还是遇到文件结尾结束 
	//feof()  // EOF - emd of file -文件结束标志
    FILE* p =fopen("test.txt","r");
	if(p == NULL)
	{
		perror("hehe");  //类似于strerror(errno)   
		               //符合语句是，里面输入的字符串会先直接输出在输出错误 
		return 0;
		}	
	 
	 int ch = 0;
	 while((ch = fgetc(p)) != EOF)
	 {
	 	putchar(ch);
	 }
	 
	 printf("\n");
	 
	 //读取错误导致结束 
	 if(ferror(p))    //   ferror 用来判断文件指针 
	 {
	 	printf("error\n");
	 }
	 
	 //正常读取结束   返回值是不为  0  的数 
	 else if(feof(p))
	 {
	 	printf("end of file\n");
	 }
	 
	  
	 fclose(p);
	 p= NULL;
	return 0;
 } 

