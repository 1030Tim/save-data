// 1. 建立linklist
// 2. 插入 add(index, value)
// 3. 刪除 del(index)

#include <stdio.h>
#include <stdlib.h>


struct Node *start = NULL;
struct Node *end = NULL;

struct Node
{
    int value;
    struct Node *next;
};

void add(const int index, const int value)
{
    // 先指向要的位置   
    int count = 0;
    struct Node *p = start;
    for (p = start; (p!=NULL && count == index-1); p = p->next)
    {
        ++count;
    }
    

}   

int main(void)
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        // 建立新的連結
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->value);
        newNode->next = NULL;
        
        // 與所有的做連接
        if (start == NULL)
        {
            start = newNode;
            end = newNode;
        }
        else
        {
            end->next = newNode;
            end = newNode;
        }
    }

    for (struct Node *p = start; p!=NULL; p = p->next)
    {
        printf("%d ", p->value);
    }
    return 0;
}