#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
void printqueue(struct node *n)
{
    printf("PRIORITY QUEUE: ");
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}
struct node *createhead(int data, int priority)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->priority = priority;
    head->next = NULL;
    return head;
}
struct node* push(struct node *head, int data, int priority)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->priority = priority;
    n->next = NULL;
    if (head->priority > n->priority)
    {
        n->next = head;
        head = n;
    }
    else
    {
        struct node *q = head;
        while (q->next != NULL && q->next->priority < q->priority)
            q = q->next;
        n->next = q->next;
        q->next = n;
    }
    return head;
}
int main(void)
{
    // Create a Priority Queue
    // 9->8->1->0
    struct node *head = createhead(0, 4);
    head=push(head, 1, 3);
    head=push(head, 9, 1);
    head=push(head, 8, 2);
    printqueue(head);
    return 0;
}