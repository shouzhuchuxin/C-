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
		while(1000*(t2-t1)/CLOCKS_PER_SEC<appe) //��ʾ�ַ�����ʱ�� 
		{                   //�˴���� ���ֻ������������� 
			t2 = clock();
		}
		printf("\r%*s",char_len,""); // \r��������Ƶ����еĿ�ͷ��
		                              // %*.*  .��ߵ�*���Կ���������ݵ���С�����ȣ�*�����滻Ϊ���� 
									  //������char_len��Ϊ��Ҫ����ĳ��� ��""������ַ��� 
		clock_t t3 = clock();
		clock_t t4 = 0;
		while(1000*(t4-t3)/CLOCKS_PER_SEC<disa)//��ʾ���ַ�����ʱ�� 
		{
			t4 = clock();
		}
	}
 } 
 //��һ�ַ�ʽ ����Sleep���� 
 void bput2(const char *s,int appe,int disa,int repe) 
 {
 	int char_len =strlen(s);
 	int i=0;
 	for(i=0;i<repe;i++)
 	{
 		printf("\r%s",s);
 		Sleep(appe); //��ʾ�ַ�����ʱ�� 
 		printf("\r%*s",char_len,"");
 		Sleep(disa);//��ʾ���ַ�����ʱ�� 
	 }
 }
int main()
{
	int appe=0,disa = 0,repe =0;
	char s[20] = "0";
	printf("������һ��������20���ڵ��ַ�����>");
	gets(s);
	printf("������ʾ�ĺ���������ʧ�ĺ�����������ִ�еĴ���\n"); 
	scanf("%d %d %d",&appe,&disa,&repe);
	bput(s,appe,disa,repe);
	bput2(s,appe,disa,repe);
}
