#include <stdio.h>
#include <stdlib.h>

struct circularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct circularqueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
int isFull(struct circularqueue *q)
{
    if ((q->r +1)%q->size== q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("circularqueue is full!!\n");
    }
    else
    {
        q->arr[q->r] = val;
        q->r=(q->r+1)%q->size;
    }
}
int dequeue(struct circularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("circularqueue is empty!!");
        return a;
    }
    else
    {
        a = q->arr[q->f];
        q->f=(q->f+1)%q->size;
        return a;
    }
}
void display(struct circularqueue *q)
{
    if (isEmpty(q))
    {
        printf("circularqueue is Empty!!\n");
    }
    else
    {
        int i = q->f;
        while (i != q->r)
        {
            printf("%d ", q->arr[i]);
            i=(i+1)%q->size;
        }
        printf("\n");
    }
}

int main(){
    struct circularqueue q;
    q.size = 5;
    q.f = q.r =0;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        printf("circularqueue is empty!!\n");
    }
    enqueue(&q, 45);
    enqueue(&q, 22);
    enqueue(&q, 78);
    enqueue(&q, 34);
    display(&q);
    if (isEmpty(&q))
    {
        printf("circularqueue is empty!!\n");
    }
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
     if (isFull(&q))
    {
        printf("circularqueue is full!!\n");
    }

    enqueue(&q, 10);
    enqueue(&q, 30);
    display(&q);
   
    if (isFull(&q))
    {
        printf("circularqueue is full!!\n");
    }
    return 0;
}