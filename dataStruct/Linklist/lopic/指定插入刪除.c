#include <stdio.h>
#include <stdlib.h>

// Node
struct Node
{
    int val;
    struct Node *next;
};

// add
void add(struct Node **head, struct Node **end, const int index, const int value)
{
    // define new Node
    struct Node *addNode = malloc(sizeof(struct Node));
    addNode->val = value;
    addNode->next = NULL;
    // except index == 0
    if (index == 0)
    {
        if ((*head) == NULL) // except list size = 0
        {
            *head = addNode;
            *end = addNode;
            return;
        }
        addNode->next = *head;
        *head = addNode;
        return;
    }

    // Search index-1
    struct Node *p = *head;
    for (int i = 0;  (i<index-1&& p->next!=NULL); ++i)
    {
        p = p->next;
    }
    // modify the link
    addNode->next = p->next;
    p->next = addNode;
    if (addNode->next == NULL)
    {
        *end = addNode;
    }
}

// pop
void pop(struct Node **head, struct Node **end, const int index)
{

    // serch to index -1 the modify link
    struct Node *p = *head;
    // except index = 0
    if (index == 0)
    {
        struct Node *temp = *head;
        if (*head == *end)
        {
            *head = NULL;
            *end = NULL;
            free(temp);
            return;
        }
    }
    for (int i = 0; (i<index-1 && p!=NULL); ++i)
    {
        p = p->next;
    }
    // modify
    struct Node *temp = p->next;
    p->next = temp->next;
    if (temp == NULL)
    {
        *end = p;
    }
    free(temp);
}


// define new list
void list(struct Node **head, struct Node **end, int n)
{
    while (n--)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        scanf("%d", &newNode->val);
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            *end = newNode;
        }
        else
        {
            (*end)->next = newNode;
            *end = newNode;
        }
    }
}
// print
void print(struct Node **head)
{
    for (struct Node *p = *head; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    // define head and end
    struct Node *head = NULL;
    struct Node *end = NULL;
    // list
    list(&head, &end, n);
    // add
    int index,value;
    printf("please enter append index and value\n");
    scanf("%d%d",&index, &value);
    add(&head, &end, index, value);
    // pop
    printf("please enter remove index\n");
    scanf("%d",&index);
    pop(&head, &end, index);
    print(&head);
    return 0;
}