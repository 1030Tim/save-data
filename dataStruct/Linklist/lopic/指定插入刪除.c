// 建立大小為n的list並append 或是 pop指定位置
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void append(struct Node **head, struct Node **end, const int index,const int value)
{
    struct Node *addNode = malloc(sizeof(struct Node));
    
    addNode->val = value;
    addNode->next = NULL;

    if (index == 0)
    {
        addNode->next = *head;
        *head = addNode;

        if (*end == NULL) *end = addNode;
        return;
    }
    // 連接Node
    struct Node *p = *head;
    for (int i = 0; (i<index-1 && p!=NULL); ++i)
    {
        p = p->next; // 只更新到index-1 , i = index-1 = p->next
    }

    addNode->next = p->next;
    p->next = addNode;

    if (*end == NULL) *end = addNode;

}

int main(void)
{
    struct Node *head = NULL;
    struct Node *end = NULL;
    int n;
    scanf("%d",&n);
    while (n--)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL;
        
        // 串起全部
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
    int k,v;
    scanf("%d%d",&k,&v);
    append(&head,&end,k,v);
    // print
    for (struct Node *p = head; p != NULL; p = p->next)
    {
        printf("%d ",p->val);
    }
}
