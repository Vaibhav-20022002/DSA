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
    struct node *n = head;
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}
struct node *delete_between(struct node *head, int key)
{
    struct node *n = head, *prev, *nn;
    while (n->data != key && n != NULL)
    {
        n = n->next;
    }
    if (n->data == key)
    {
        prev = n->prev;
        nn = n->next;
        prev->next = n->next;
        nn->prev = n->prev;
        free(n);
    }
    return head;
}
struct node *delete_end(struct node *head)
{
    struct node *n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    struct node *p = n->prev;
    p->next = NULL;
    free(n);
    return head;
}
struct node *deletehead(struct node *head)
{
    struct node *n = head;
    struct node *p = n->next;
    free(n);
    return p;
}
int main(void)
{
    struct node *head, *second, *third, *fourth, *fifth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = second;
    second->prev = head;
    second->data = 8;
    second->next = third;
    third->prev = second;
    third->data = 4;
    third->next = fourth;
    fourth->prev = third;
    fourth->data = 2;
    fourth->next = NULL;
    printf("THE OLD DLL IS:\n");
    printdll(head);
    head = delete_between(head, 4);
    head = delete_end(head);
    head = deletehead(head);
    printf("\nTHE NEW DLL IS:\n");
    printdll(head);
    return 0;
}