// 輸入大小為n的list並將值插入指定位置
#include <stdio.h>
#include <stdlib.h>

// 定義Node
struct Node
{
    int val;
    struct Node *next;
};

void add(struct Node **head, struct Node **end, const int index, const int value)
{
    struct Node *addNode = malloc(sizeof(struct Node));
    addNode->val = value;
    addNode->next = NULL;
    // 找到index前面一個點
    
    struct Node *p = *head;
    if (index == 0){
        if (*head == NULL)
        {
            *head = addNode;
            *end = addNode; 
            return;
        }
        addNode->next = *head; 
        *head = addNode; 
        return;
    }
    int i;
    for (i = 0; (i<index-1 && p->next != NULL); ++i)
    {
        p = p->next; // 找到index-1的點
    }
    // 接線
    addNode->next = p->next;
    p->next = addNode;
    if (p == *end)
    {
        *end = addNode;
    }
}

// head, end
int main(void)
{
    int n;
    scanf("%d",&n);
    struct Node *head = NULL;
    struct Node *end = NULL;

    while (n--)
    {
        struct Node *netNode = malloc(sizeof(struct Node));
        scanf("%d", &netNode->val);
        netNode->next = NULL;

        if (head == NULL)
        {
            head = netNode;
            end = netNode;
        }
        else
        {
            end->next = netNode;
            end = netNode;
        }
    }
    int k,v;
    scanf("%d%d",&k,&v);
    add(&head, &end, k,v);

    for (struct Node *p = head; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    return 0;
}