#include<stdio.h>
#include<string.h>
int panduan(int* p, int k)
{
  
    int i = 0, j = 0;
    for (i = k - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (*(p + i) == *(p + j))
                return *(p + i);
        }
    }
    ;
}
int main()
{
    int x = 0;
    int arr[10000] = { '0' };
    int k = sizeof(arr)/sizeof(arr[0]);
    int n = 1,j=0;
    while (n)
    {
        for (x = 0; x < k; x++)
        {
            scanf_s("%d", arr + x);
            j++;
            if (getchar() == '\n')
                break;
        }
        for (x = 0; x < j; x++)
        {
            if (*(arr + x) >= 0 && *(arr + x) < 10000);
            else
            {
                printf("-1");
                continue;
            }
        }
        n = 0;
    }
    int num = panduan(arr,j);
    printf("重复的数字为：%d\n", num);
    return 0;
}