#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val; // 儲存的資料
    struct Node* next; // 下一個指向的節點
};

int main(void)
{
    struct Node* head = malloc(sizeof(struct Node));
    head->val = 10;
    head->next = NULL;

    printf("%d\n",head->val); 
    return 0;
}