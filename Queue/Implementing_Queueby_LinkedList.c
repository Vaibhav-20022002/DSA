#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
void printlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node *));
    if (n == NULL)
    {
        printf("QUEUE IS OVERFLOWED !");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (r == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
        return r->data;
    }
}
int dequeue()
{
    if (f == NULL)
    {
        printf("\nQUEUE UNDERFLOWED!\n");
    }
    else
    {
        struct node *ptr = f;
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}
int main(void)
{
    printf("%d ENQUEUED TO THE QUEUE!\n", enqueue(8));
    printf("%d ENQUEUED TO THE QUEUE!\n", enqueue(2));
    printf("%d ENQUEUED TO THE QUEUE!\n", enqueue(5));
    printf("THE QUEUE AFTER ENQUEUING IS: ");
    printlist(f);
    printf("\n%d DEQUEUED FROM THE QUEUE!\n", dequeue());
    printf("THE QUEUE AFTER DEQUEUING IS: ");
    printlist(f);
    return 0;
}