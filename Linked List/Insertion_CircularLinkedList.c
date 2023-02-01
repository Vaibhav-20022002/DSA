#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void printlist(struct node *head)
{
    struct node *n = head;
    do
    {
        printf("%d ", n->data);
        n = n->next;
    } while (n != head);
}
struct node *addatbeginning(struct node *head, int newdata)
{
    struct node *n = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = newdata;
    n = n->next;
    while (n->next != head)
    {
        n = n->next;
    }
    n->next = new;
    new->next = head;
    head = new;
    return head;
}
struct node *addatend(struct node *head, int newdata)
{
    struct node *n = head;
    n = n->next;
    while (n->next != head)
    {
        n = n->next;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = newdata;
    n->next = new;
    new->next = head;
    return head;
}
struct node *addinbetween(struct node *head, int newdata, int addafter)
{
    struct node *n = head->next;
    struct node *p = head;
    while (p->data != addafter && p != NULL)
    {
        p = n;
        n = n->next;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = newdata;
    new->next = n;
    p->next = new;
    return head;
}
int main(void)
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 4;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = head;
    printf("CIRCULAR LINKED LIST BEFORE INSERTION IS:\n");
    printlist(head);
    head = addatbeginning(head, 0);
    head = addatend(head, 6);
    head = addinbetween(head, 3, 2);
    printf("\nCIRCULAR LINKED LIST AFTER INSERTION IS:\n");
    printlist(head);
    return 0;
}