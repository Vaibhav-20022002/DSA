#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}
struct node *exchange_nodes(struct node *head, int key1, int key2)
{
}
int main(void)
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->next = second;
    second->data = 15;
    second->next = third;
    third->data = 12;
    third->next = fourth;
    fourth->data = 13;
    fourth->next = fifth;
    fifth->data = 20;
    fifth->next = sixth;
    sixth->data = 14;
    sixth->next = NULL;
    printf("Linked List before Insertion:\n");
    printlist(head);
    head = exchange_nodes(head, 12, 20);
    printf("\nLinked List after Insertion:\n");
    printlist(head);
    return 0;
}