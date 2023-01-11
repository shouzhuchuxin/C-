# include <stdio.h>
# include <string.h>
# include <assert.h>
void left_remove1(char* p, const int k)
{
	assert(p);
	int i = 0;
	int len = strlen(p);
	for (i = 0; i < k; i++)
	{
       char tmp = *p;
	   int j = 0;
	   for (j = 0; j < len -1; j++)
	   {
            
			*(p+j) = *(p +j+ 1);
			
	   }
	   
	   *(p + len - 1) = tmp;
	}
	
}
void remove(char* left, char* right)
{
	assert(left!=NULL);
	assert(right!=NULL);
	while ( left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_remove2(char* p, const int k)
{
	assert(p!=NULL);	
	int len = strlen(p);
	remove (p,p+ k-1);//逆序左边
	remove (p+k, p+len-1);//逆序右边
	remove(p, p + len - 1);//逆序整体
}

int  left_remove3(char* p1, char* p2)
{
	assert(p1);
	assert(p2);
	int len = strlen(p1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_remove1(p1, 1);
		int ret = strcmp(p1, p2);
		if (ret == 0)
			return 1;
	}
	return 0;
}
int  main()
{

	//旋转字符串
	char arr[] = { "abcdef" };
	int k = 0;
	printf("请输入一个不大于字符串长度的整数。\n");
	int q=strlen(arr);
	scanf_s("%d", &k);
	assert(k < q);
	left_remove1(arr, k);
    printf("旋转后的字符串为：%s\n", arr);

	
	
	//三步翻转法
	char arr0[] = { "bcdefg" };
	left_remove2(arr0, k);
	printf("%s\n", arr0);


	//判断一个字符串是否又另一个字符串旋转所得
	char arr1[] = { "abcdef" };
	char arr2[] = { "cdefab" };
	int ret =left_remove3(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
