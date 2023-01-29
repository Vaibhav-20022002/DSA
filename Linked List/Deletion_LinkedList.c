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

struct node *deletenodeofvalue(struct node *head, int key)
{
    struct node *n = head, *prev;
    while (n->data != key && n->next != NULL)
    {
        prev = n;
        n = n->next;
    }
    if (n->data == key)
    {
        prev->next = n->next;
        free(n);
    }
    return head;
}
struct node *deletefirstnode(struct node *head)
{
    struct node *n = head;
    head = head->next;
    free(n);
    return head;
}
struct node *deletelastnode(struct node *head)
{
    struct node *n = head, *prev;
    while (n->next != NULL)
    {
        prev = n;
        n = n->next;
    }
    prev->next = NULL;
    free(n);
    return head;
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
    printf("OLD NODE\n");
    printlist(head);
    head = deletenodeofvalue(head, 3);
    head = deletefirstnode(head);
    head = deletelastnode(head);
    printf("\nNEW NODE\n");
    printlist(head);
    return 0;
}