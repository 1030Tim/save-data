#include <stdio.h>

int BinarySearch(const int size, const int flag, int arr[]) // O(n log n)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left+right)/2;
        if (arr[mid] > flag) right = mid-1;
        else if (arr[mid] < flag) left = mid+1;
        else return mid;
    }
    return -1;
}

void sort(const int size, int arr[]) // O(n^2)
{
    int i,j;
    for (i = 0; i<size; ++i)
    {
        for (j = 0; j<size-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

int main(void)
{
    int i,n = 10, arr[10];
    for (i = 0; i<n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    sort(n, arr);

    int flag;
    printf("Enter flag\n");
    scanf("%d", &flag);
    int index = BinarySearch(n, flag, arr);
    if (index >= 0)
    {
        printf("is in %d\n", index);
    }
    else
    {
        printf("Not value\n");
    }

    for (i = 0; i<n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}