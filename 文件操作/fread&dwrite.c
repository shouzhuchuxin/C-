#include<stdio.h>
struct S 
{
	char name[10];
	int age;
	float n;
};
int main()
{
  	
    struct S s = {"����",10,3.14};	
    struct S tmp = {0};
    
	FILE* p =fopen("test.txt","w");
	if(p == NULL)
	{
		return 0;
	}
	//�����Ƶ���ʽд�ļ�
	fwrite(&s,sizeof(struct S), 1 ,p);  
	 
	 fclose(p);
	 p = NULL;
	 
	 FILE*p1=fopen("test.txt","rb");
	 if(p1 == NULL)
	 {
	 	return 0;
	 }
	 
	 //�����Ƶ���ʽ���ļ�
	 
	 fread(&tmp,sizeof(struct S),1,p1);
	 printf("%s %d %1f\n",tmp.name,tmp.age,tmp.n);
	 
	 fclose(p1);
	 p1 =NULL; 
	return 0;
	
 } 
