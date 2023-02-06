#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int f, r, *arr, size;
};
int enqueue(struct queue *q, int value)
{
    if ((q->r + 1) % q->size == q->f)
        printf("QUEUE IS OVERFLOWED!!\n");
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
        return q->arr[q->r];
    }
}
int dequeue(struct queue *q)
{
    if (q->f == q->r)
        printf("QUEUE IS UNDERFLOWED!!\n");
    else
    {
        q->f = (q->f + 1) % q->size;
        return q->arr[q->f];
    }
}
int queuetop(struct queue *q)
{
    return q->arr[q->f + 1];
}
int queueend(struct queue *q)
{
    return q->arr[q->r];
}
int main(void)
{
    struct queue *q = malloc(sizeof(struct queue));
    q->f = q->r = -1;
    q->size = 8;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 2));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 7));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 8));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 5));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 9));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 8));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 1));
    printf("%d ENQUEUED TO THE QUEUE\n", enqueue(q, 0));
    printf("%d DEQUEUED FROM THE QUEUE\n", dequeue(q));
    printf("THE FRONT-MOST ELEMENT IS: %d\n", queuetop(q));
    printf("THE BOTTOM-MOST ELEMENT IS: %d\n", queueend(q));
    return 0;
}