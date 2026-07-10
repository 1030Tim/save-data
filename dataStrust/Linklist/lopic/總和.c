// 輸入n個整數並計算總和
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val; // 值
    struct Node* next;  // 下一個是誰
};

int main(void)
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    struct Node *head = NULL;
    struct Node *end = NULL;

    // input data
    while (n--)
    {
        // initialization
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL;
        sum += newNode->val;

        // set Node
        if (head == NULL)
        {
            head = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode; // 與下一個newNode做連接
            end = newNode; // 結束是下一個

        }
    }
    // output data

    for (struct Node *p; p != NULL; p = p->next)
    {
        printf("%d ",p->val);
    }
    printf("\nsum = %d\n",sum);
    return 0;
}