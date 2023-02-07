#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isempty(struct queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}
int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}
int enqueue(struct queue *q, int value)
{
    if (isfull(q))
    {
        printf("QUEUE IS OVERFLOW !!!");
    }
    else
    {
        ++q->r;
        q->arr[q->r] = value;
        return q->arr[q->r];
    }
}
int dequeue(struct queue *q)
{
    if (isempty(q))
    {
        printf("THE QUEUE IS UNDERFLOW !!!");
    }
    else
    {
        ++q->f;
        return q->arr[q->f];
    }
}
int frontelement(struct queue *q)
{
    return q->arr[q->f + 1];
}
int rearelement(struct queue *q)
{
    return q->arr[q->r];
}
int main(void)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    printf("%d ENQUEUED TO QUEUE\n", enqueue(q, 10));
    printf("%d ENQUEUED TO QUEUE\n", enqueue(q, 20));
    printf("%d ENQUEUED TO QUEUE\n", enqueue(q, 30));
    printf("%d ENQUEUED TO QUEUE\n", enqueue(q, 40));
    printf("%d DEQUEUED FROM QUEUE\n", dequeue(q));
    printf("FRONT ELEMENT :%d\n", frontelement(q));
    printf("REAR ELEMENT :%d\n", rearelement(q));
    return 0;
}