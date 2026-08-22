// 1. 建立linklist
// 2. 插入 add(index, value)
// 3. 刪除 del(index)
#include <stdio.h>
#include <stdlib.h>

struct Node *head = NULL;
struct Node *end = NULL;
struct Node
{
    int value; // 裡面的值
    struct Node *next; // 存放下一個的值
};

void newNodes(int n)
{
    while (n--)
    {
        struct Node *newNode = malloc(sizeof(struct Node)); // 開一個新的節點   
        scanf("%d", &newNode->value); // 賦予值給新節點
        newNode->next = NULL;

        // 嫁接
        if (head == NULL) // 假設還沒有串列
        {
            head = newNode; // 設定為開始值
            end = newNode;
        }
        else 
        {
            end->next = newNode; // 前一個值的下一個替換
            end = newNode; // 串上去
        }
    }
}

void add(int index, const int value)
{ // 缺少判定index = 0
    int count = 0;
    struct Node *p = NULL;
    for (p = head; (count < index-1 && p!=NULL); p = p->next) ++count;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = p->next->next;
    p->next = newNode;
}

int main()
{
    int n; // 建立幾個陣列
    scanf("%d", &n);

    newNodes(n);
   
    struct Node *p = NULL;

    add(0,77);
    for (p = head; p!=NULL; p = p->next)
    {
        printf("%d ", p->value);
    }
    return 0;
}