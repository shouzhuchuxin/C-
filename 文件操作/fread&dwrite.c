#include<stdio.h>
struct S 
{
	char name[10];
	int age;
	float n;
};
int main()
{
  	
    struct S s = {"张三",10,3.14};	
    struct S tmp = {0};
    
	FILE* p =fopen("test.txt","w");
	if(p == NULL)
	{
		return 0;
	}
	//二进制的形式写文件
	fwrite(&s,sizeof(struct S), 1 ,p);  
	 
	 fclose(p);
	 p = NULL;
	 
	 FILE*p1=fopen("test.txt","rb");
	 if(p1 == NULL)
	 {
	 	return 0;
	 }
	 
	 //二进制的形式读文件
	 
	 fread(&tmp,sizeof(struct S),1,p1);
	 printf("%s %d %1f\n",tmp.name,tmp.age,tmp.n);
	 
	 fclose(p1);
	 p1 =NULL; 
	return 0;
	
 } 
