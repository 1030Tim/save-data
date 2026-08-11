// 1. 先出來基本的linklist
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

int main(void)
{
    int n = 5;
    struct Node *start = NULL, *end = NULL;
    while (n--)
    {
        
        struct Node *newNode = malloc(sizeof(struct Node));
        int value;
        scanf("%d", &value);
        newNode->value = value;
        newNode->next = NULL; // 設定單獨的點

        if (start == NULL)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode; // 原本的指向自己
            end = newNode; // 原本的end變成現在新的
        }
    }

    for (struct Node *p = start; p != NULL; p = p->next)
    {
        printf("%d ", p->value);
    }
}