#include<stdio.h>
#include<assert.h>
struct S
{
	char name[20]; //  ע��˴�[20]���ô� 
	int age;
};
void * my_memcpy(void*p1, const void* p2,size_t a) //size_t���������͵����� 
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	
	void*ret = p1;
	while(a--)
	{
		*((char*)p1) = *((char*)p2);
	     (char*)p1++;
	     (char*)p2++;
	}
	return ret;       //���ص�Ϊ��ָ��Ӧ�þͿ��� 
}
int main()
{
   struct S s[]={{"����",10},{"����",20}};
   struct S a[3] ={0};
   my_memcpy(a,s,sizeof(s));  //���һ������Ϊ��Ҫ�������ֽ��� 
   int i=0;
   for(i=0;i<2;i++)
   {
   	  printf("%s\n%d\n",&(a[i].name),a[i].age);  //��� �ַ���ʱ ��Ҫ��ַ 
   }
	return 0;
}
