#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
void printstack(struct stack *s)
{
    for (int i = 0; i <= s->top; ++i)
    {
        printf("%d ", s->arr[i]);
    }
}
int isfull(struct stack *n)
{
    if (n->top == n->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s, int value)
{
    if (s->top == s->size - 1)
    {
        printf("STACK IS OVERFLOW !!\n");
    }
    else
    {
        ++s->top;
        s->arr[s->top] = value;
    }
}
void pop(struct stack *s)
{
    if (s->top < 0)
    {
        printf("STACK IS UNDERFLOW !");
    }
    else
    {
        --s->top;
    }
}
int peek(struct stack *s, int i)
{
    int arrayInd = s->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return s->arr[arrayInd];
    }
}
int main(void)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    printf("STACK HAS BEEN CREATED SUCCESSFULLY !\n");
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    printf("THE STACK AFTER _PUSH() IS: \n");
    printstack(s);
    for (int i = 0; i < s->size; ++i)
    {
        pop(s);
    }
    printf("\nTHE STACK AFTER _POP() IS: \n");
    printstack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 10);
    push(s, 6);
    push(s, 79);
    push(s, 8);
    printf("THE POSITION OF THE ELEMENT IS: %d", peek(s,2));
    return 0;
}