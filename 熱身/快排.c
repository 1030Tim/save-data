#include <stdio.h>

void quick_sort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    
    int i = left;
    int j = right;
    int pivot = arr[(left+right)/2];

    while (i <= j)
    {
        while (arr[i] < pivot) ++i; // 從前面找有沒有大於中間值的
        while (arr[j] > pivot) --j; // 從後面找有沒有小於中間值的
    
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j]; // 與標記的做交換
            arr[j] = temp;

            ++i;
            --j;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
    return;
}

int main(void)
{
    int arr[10] = {0,11,22,33,55,66,77,99,88,44};
    int left = 0, right = 9;
    quick_sort(arr,left,right);

    for (int i = 0; i<10; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}