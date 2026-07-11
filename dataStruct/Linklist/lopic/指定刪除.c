// 建立大小為n的list並pop指定位置
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void pop(struct Node **head, struct Node **end, const int index)
{
    if (*head == NULL) return;
    // 走訪到index-1更改指針
    if (index == 0)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);

        if (*head == NULL) *end = NULL;
        return;
    }

    struct Node *p = *head;
    for (int i = 0; (i<index-1 && p!=NULL); ++i)
    {
        p = p->next; // 一直抓下一個人
    }
    
    if (p == NULL || p->next == NULL) return;

    struct Node *temp = p->next;
    p->next = temp->next;

    if (temp == *end) *end = p;
    free(temp);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    struct Node *head = NULL;
    struct Node *end = NULL;

    while (n--)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

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
    int index;
    printf("指定刪除的位置: ");
    scanf("%d",&index);
    pop(&head,&end,index);
    for (struct Node *p = head; p!=NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("\n");
    return 0;
}