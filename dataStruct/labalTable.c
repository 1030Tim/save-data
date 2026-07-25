// LabalTable
#include <stdio.h>
int main(void)
{
    // 原本的陣列
    int size = 5;
    int arr[5] = {0,1,3,4,5};
    // 要插入的值的
    int add = 2;
    // 在哪裡插入
    int w = 1;

    for (int i = 0; i<size; ++i)
    {
        if (i == w+1)
        {
            printf("%d ",add);
        }
        printf("%d ",arr[i]);
    }
    return 0;
}