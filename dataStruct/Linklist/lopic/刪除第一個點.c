// 建立一個大小為n的linklist並刪除第一個值
#include <stdio.h>
#include <stdlib.h>
// 定義 Node
struct Node
{
    int val;
    struct Node *next;
};

void pop(struct Node **head)
{
    if (*head == NULL) return;
    struct Node *temp = *head; // 避免memory leak一定要有一個指標
    (*head) = (*head)->next;
    free(temp); // 記憶體回收
}

int main(void)
{
    // 定義head 跟 end
    struct Node *head = NULL;
    struct Node *end = NULL;
    int n;
    scanf("%d",&n);

    while (n--)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL; // 設定完值next一定要NULL

        if (head == NULL)
        {
            head = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }
    pop(&head);
    for (struct Node *p = head; p!=NULL; p = p->next)
    {
        printf("%d ", p->val);
    }


}