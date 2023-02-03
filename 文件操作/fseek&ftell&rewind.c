#include<stdio.h>
int main ()
{
	FILE*p = fopen("test.txt","w");
	
	fputs("abcdef",p);
	fclose(p);
	p = NULL;
	
	FILE*p1 = fopen("test.txt","r");
	
		//定位文件指针 
	fseek(p1,2,SEEK_SET);     // 第一个参数是文件指针  二为偏移量  三为：文件指针的位置 
	
	//SEEK_CUR  文件指针的当前位置
	//SEEK_END  文件的末尾位置
	//SEEK_SET   文件起始位置 
	
    int ch =fgetc(p1);  
	printf("%c\n",ch);//c
	
	//ftell  文件指针相对于起始位置的偏移量
	int a =ftell(p1);
	printf("%d\n",a);
	
	//rewind  让文件指针的位置回到起始位置
	 rewind(p1);
	  ch =fgetc(p1);
	  printf("%c\n",ch);
	  
	fclose(p1);
	p = NULL;
	return 0;
 } 
