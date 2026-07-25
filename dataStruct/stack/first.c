#include <stdio.h>

void push(int* top, int value, int arr[])
{
    if (*top < 5)
    {
        arr[++*top] = value;
    }
    else return;
}
void pop(int* top, int arr[])
{
    if (*top > -1)
        arr[*top--] = -1;
    else return;
}

int main()
{
    int top = -1, count = 0;
    int arr[10];
    

    while (top < 5)
    {
        char ans[5];
        printf("push or pop\n");
        scanf("%s", ans);
        
        if (ans[1] == 'u')
        {
            int k;
            printf("enter data \n");
            scanf("%d", &k);
            push(&top,k,arr);
            ++top;
            //printf("%c ",ans[1]);
        }
        
        else
        {
            pop(&top, arr);
            --top;
        }

    }
    printf("==========\n");
    for (int i = 0; i<10; ++i)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}