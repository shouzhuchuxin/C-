#include<stdio.h>
#include<assert.h> 
void move(int *arr,const int sz)
{
	assert(arr);
	int left =0;
	int right =sz - 1;
	while(left < right)
	{
		while((left < right)&&*(arr+left)%2 == 1)//left < right此条件确保当数组中全为偶数或奇数时不会越界访问 
	   {
		left++;
	   }
	while((left < right)&&*(arr + right)%2 == 0)
	   {
	 	right--;
	   }
	int tmp =0;
	if(left < right)
	{
		tmp= *(arr + left);
	    *(arr + left) = *(arr + right);
	    *(arr + right) = tmp;
	}
	}
	 
}
void move1(int arr[] , int sz)
{
	int left =0;
	int right =sz - 1;
	while(left < right)
	{
		while((left < right)&&arr[left]%2 == 1)//left < right此条件确保当数组中全为偶数或奇数时不会越界访问 
	   {
		left++;
	   }
	while((left < right)&&arr[right]%2 == 0)
	   {
	 	right--;
	   }
	int tmp =0;
	if(left < right)
	{
		tmp= arr[left];
	    arr[left] = arr[right];
	    arr[right] = tmp;
	}
	}
}
 
void main()
{
	
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	move(arr,sz);
	//move1(arr,sz);
	int i=0;
	for(i = 0;i < sz;i++)
	printf("%d ",arr[i]);
	
}
