#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 2)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full!!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue is empty!!");
        return a;
    }
    else
    {
        a = q->arr[q->f];
        q->f++;
        return a;
    }
}
void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("queue is Empty!!\n");
    }
    else
    {
        int i = q->f+1;
        while (i != q->r)
        {
            printf("%d ", q->arr[i]);
            i++;
        }
        printf("%d\n",q->arr[q->r]);
    }
}

int main()
{
    struct queue q;
    q.size = 50;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        printf("queue is empty!!\n");
    }
    enqueue(&q, 22);
    enqueue(&q, 78);
    enqueue(&q, 45);
    enqueue(&q, 34);
    display(&q);
    if (isEmpty(&q))
    {
        printf("queue is empty!!\n");
    }
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 10);
    enqueue(&q, 30);
    display(&q);
   
    if (isFull(&q))
    {
        printf("queue is full!!\n");
    }
    return 0;
}