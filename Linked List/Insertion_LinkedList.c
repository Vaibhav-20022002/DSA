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
struct node *addnodeatfirst(struct node *head, int newdata)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = newdata;
    n->next = head;
    return n;
}
struct node *addafternode(struct node *head, struct node *prevnode, int newdata)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = newdata;
    n->next = prevnode->next;
    prevnode->next = n;
    return head;
}
struct node *addnodeatend(struct node *head, int newdata)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = newdata;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = n;
    n->next = NULL;
    return head;
}
int main(void)
{
    struct node *head;
    struct node *second;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;
    printf("OLD NODE:\n");
    printlist(head);
    head = addnodeatfirst(head, 0);
    head = addafternode(head, second, 3);
    head = addnodeatend(head, 5);
    printf("\nNEW NODE\n");
    printlist(head);
    return 0;
}