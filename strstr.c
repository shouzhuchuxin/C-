#include<stdio.h>
#include<assert.h>
char* my_strstr(const char*p1,const char*p2)//�����Ӵ��ĺ��� 
{
	assert(p1!=NULL);
	assert(p2!=NULL);
	char*s1=NULL;
	char*s2=NULL;
	char*cat=(char*)p1; // p1������Ϊconst char*��ǿ������ת��Ϊchar* 
	while(*cat)
	{
	    s1=cat;
		s2=(char*)p2;
		
		if(p2 == '\0')
		{
			return (char*)p1;
		}
		
		while(*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return cat;
		}
		if(*s1 == '\0')
		{
			return NULL;
		}
		cat++;
	}
}
int main()
{
	char*p1="abbbcdef";
	char*p2="bcd";
	char*ret = my_strstr(p1,p2);
	if(ret == NULL)
	printf("�������Ӵ���\n");
	else 
	printf("%s",ret);
	return 0;
}
//����˼·Ϊ��
//1.����ָ��s1��s2��act
//           s1 s2 ����Ϊ��ָ��   actָ��p1
//2.����һ��whileѭ������Ϊ*act��=0
//  �����whileѭ���У�������s1=act  s2=p2 
// Ȼ�����һ��whileѭ������while�����ж������ַ��Ƿ����
// �������� ����ѭ����act��ַ��һ �ڽ����ʼ��whileѭ�� 
// ������ε�whileѭ���У�act��ַ�Ѿ���һ s1��ָ��Ҳ�����ı� s2δ�ı�   
