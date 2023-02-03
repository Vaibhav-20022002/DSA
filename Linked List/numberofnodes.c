#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int countnode(struct node *head)
{
    struct node *n = head;
    int counter = 0;
    while (n != NULL)
    {
        ++counter;
        n = n->next;
    }
    return counter;
}
int main(void)

{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;
    printf("THE NUMBER OF NODES ARE: %d", countnode(head));
    return 0;
}