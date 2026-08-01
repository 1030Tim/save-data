// ([{}])

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[1000];
int top = -1; // 預設是空的

void push(const char *arr)
{
    for (int i = 0; i < (int)strlen(arr); ++i)
    {
        stack[++top] = arr[i];
    }
    return;
}

char pop()
{
    char temp = stack[top];
    stack[top--] = '0';
    return temp;
}

int main(void)
{
    char arr[1000];
    scanf("%s", arr);

    push(arr);
    // i <= 因為還有結尾
    for (int i = 0; i <= top; ++i)
    {
        printf("%c ", stack[i]);
    }
    printf("\n");
    int count = 0;
    for (int i = 0; i<=top; ++i)
    {
        if (arr[i] == '(' && pop() == ')') ++count;
        else if (arr[i] == '{' && pop() == '}') ++count;
        else if (arr[i] == '[' && pop() == ']') ++count;
    }
    if (count == strlen(arr)) printf("Ok");
    

    return 0;
    
}
