#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow!! cannot push %d in stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!! cannot pop from the stack.");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Not a valid position.");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}
void display(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("stack is empty!!\n");
    }
    else{
        int i=ptr->top;
        while(i!=-1){
            printf("%d ",ptr->arr[i]);
            i--;
        }
        printf("\n");
    }
}

int main()
{
    struct stack s;
    s.size = 10;
    s.top = -1;
    s.arr = (int *)malloc(s.size * sizeof(int));
    printf("Stack is createsd succesfully\n");
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    printf("%d\n",peek(&s,1));
    pop(&s);
    printf("%d\n",peek(&s,1));
    push(&s,6);
    push(&s,7);
    display(&s);
    printf("%d\n",peek(&s,1));

    return 0;
}