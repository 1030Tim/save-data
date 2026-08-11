#include <stdio.h>

int n,arr[1000];

void sort()
{
    for (int i = 0; i<n; ++i)
    {
        for (int j = 0; j<n-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

void input()
{
    for (int i = 0; i<n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    return;
}

void print()
{
    int max = -1000, min = 10000;
    for (int i = 0; i<n; ++i)
    {
        if (arr[i] >= 60 && arr[i] < min)
            min = arr[i];
        else if (arr[i] < 60 && arr[i] > max)
            max = arr[i];

        if (i < n-1)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);

    }
    if (max == -1000) printf("best case\n");
    else printf("%d\n", max);

    if (min == 10000) printf("worst case\n");
    else printf("%d\n", min);
    
    return;
}

int main(void)
{
    scanf("%d", &n);
    input();
    sort();
    print();

    return 0;
}