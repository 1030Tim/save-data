// i have push 10 value for stack, then print all value
#include <stdio.h>

int stack[9];
int top = -1;

// pop to stack
int pop()
{
    if (top <= -1)
    {
        printf("Underflow\n");
        return 0;
    }
    //printf("%d ", top);
    int temp = stack[top];
    stack[top--] = -1;
    return temp;
}

// push to stack
void push(int value)
{
    if (top >= 9)
    {
        printf("Overflow\n");
        return;
    }
    stack[++top] = value;
    return;
}

// main of program
int main(void)
{
    for (int i = 0; i<10; ++i)
    {
        int value;
        scanf("%d", &value);
        push(value);
    }
    for (int i = 0; i<10; ++i)
    {
        printf("%d ", pop());
    }
    return 0;
}