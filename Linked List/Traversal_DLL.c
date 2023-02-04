#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void printdll(struct node *head)
{
    printf("THE FORWARD DLL IS:\n");
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\nTHE REVERSED DLL IS:\n");
    n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->prev;
    }
}
int main(void)
{
    struct node *head, *second, *third, *fourth, *fifth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 1;
    head->next = second;
    second->prev = head;
    second->data = 7;
    second->next = third;
    third->prev = second;
    third->data = 8;
    third->next = fourth;
    fourth->prev = third;
    fourth->data = 6;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->data = 4;
    fifth->next = NULL;
    printdll(head);
    return 0;
}