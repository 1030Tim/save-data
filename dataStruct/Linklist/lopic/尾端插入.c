// 建立一個大小為n的linklist並在最後插入6

// 建立value, next
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
void append(const int value, struct Node **end)
{
    struct Node *addNode = malloc(sizeof(struct Node));
    addNode->next = NULL;
    addNode->val = value;
    (*end)->next = addNode;
    *end = addNode;
}
int main(void)
{
    // 建立 head, end
    struct Node *head = NULL;
    struct Node *end = NULL;

    int n;
    scanf("%d",&n);
    
    while (n--)
    {
        // 建立新的點
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        // 下一個點為NULL
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
    // append 6
    printf("要新增值:");
    int k;
    scanf("%d",&k);
    append(k,&end);
    // output
    for (struct Node *p = head; p!=NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("\n");
    return 0;
}