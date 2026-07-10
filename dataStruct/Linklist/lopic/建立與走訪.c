// 利用linkList建立大小為n的串列並輸出
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val; 
    struct Node* next;
};

int main(void)
{
    int n;
    scanf("%d",&n);
    struct Node* head =  NULL, *end = NULL;


    while (n--)
    {
        struct Node *node = malloc(sizeof(struct Node));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head == NULL) // 判斷是不是第一個節點 
        {
            head = end = node;
        }
        else
        {
            end->next = node; // 原本的結尾是NULL改成node
            end = node;
        }
    }

    for (struct Node *p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    return 0;
}