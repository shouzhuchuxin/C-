#include<stdio.h>
#include<assert.h>
void* my_memmove(void*p1,const void*p2,size_t count)
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	
	char *ret =p1;
	if(p1<p2)                   //ͨ��p1 p2 ��ַ���Ⱥ�˳��ѡ��ͬ�Ľ������� 
	{
		while(count--)         // ��ǰ->�� 
		{
			*(char*)p1 = *(char*)p2;
			(char*)p1++;
			(char*)p2++;
		}
	}
	else 
	{
		while(count--)          // �Ӻ�-> ǰ 
		{
			*((char*)p1 + count ) = *((char*)p2 + count ) ;
		}
	}
	return ret;
}
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	my_memmove(a,a+2,20);  // ��a+2��ַ����ʼ��20���ֽڿ�����a��ʼ�ĵ�ַ�� 
	int i=0;
	for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
	printf("%d",a[i]); 
	
	//    memset  �ڴ�����:
	 char arr[10] = {0};
	 memset(arr,'#',10);   //  '#'Ϊ��һ���ֽڵĵ�ַ�д�ŵĶ���   10 Ϊ��ŵ��ֽ��� 
    // �����÷���
	int arr1[10] = {0};
	  //memset(arr1,1,10);  //  ������Ϊint ���� ռ40���ֽ� ֻ���10���ֽڵ�1�Ǵ���� 
	return 0;
}
