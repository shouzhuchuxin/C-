#include<stdio.h> 
#include<string.h>
#include<time.h>
#include<windows.h> 
void bput(const char *s,int appe,int disa,int repe)
{
	int char_len = strlen(s);
	int i=0;
	for(i=0;i< repe;i++)
	{
		printf("\r%s",s);
		clock_t t1 = clock();
		clock_t t2 = 0; 
		while(1000*(t2-t1)/CLOCKS_PER_SEC<appe) //显示字符串的时间 
		{                   //此处详解 见手机！！！！！！ 
			t2 = clock();
		}
		printf("\r%*s",char_len,""); // \r（将光标移到本行的开头）
		                              // %*.*  .左边的*可以控制输出内容的最小输出宽度，*可以替换为数字 
									  //此列中char_len即为需要输出的长度 ，""代表空字符串 
		clock_t t3 = clock();
		clock_t t4 = 0;
		while(1000*(t4-t3)/CLOCKS_PER_SEC<disa)//显示空字符串的时间 
		{
			t4 = clock();
		}
	}
 } 
 //另一种方式 利用Sleep函数 
 void bput2(const char *s,int appe,int disa,int repe) 
 {
 	int char_len =strlen(s);
 	int i=0;
 	for(i=0;i<repe;i++)
 	{
 		printf("\r%s",s);
 		Sleep(appe); //显示字符串的时间 
 		printf("\r%*s",char_len,"");
 		Sleep(disa);//显示空字符串的时间 
	 }
 }
int main()
{
	int appe=0,disa = 0,repe =0;
	char s[20] = "0";
	printf("请输入一个长度在20以内的字符串：>");
	gets(s);
	printf("输入显示的毫秒数，消失的毫秒数，反复执行的次数\n"); 
	scanf("%d %d %d",&appe,&disa,&repe);
	bput(s,appe,disa,repe);
	bput2(s,appe,disa,repe);
}
