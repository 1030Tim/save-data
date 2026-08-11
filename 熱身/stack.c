#include <stdio.h>

int stack[5];
int top = -1;

void push(const int value)
{
    if (top >= 4) return;
    stack[++top] = value;
    return;
}
int pop()
{
    return stack[top--];
}

int main(void)
{
    for (int i = 0; i<5; ++i)
    {
        int k;
        scanf("%d", &k);
        push(k);
    }
    while (top >= 0)
    {
        printf("pop %d\n", pop());
    }
    return 0;
}