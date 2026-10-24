#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* f=NULL;
struct node* r=NULL;

void enqueue(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("queue is full!!!\n");
    }
    else
    {
        newnode->data = value; 
        newnode->next = NULL;
        if (f == NULL)
        {
            f = r = newnode;
        }
        else
        {
            r->next = newnode;
            r = newnode;
        }
    }
}
int dequeue()
{
    int val=-1;
    if(f==NULL){
        printf("queque is empty\n");
    }
    else{
        struct node*ptr;
        ptr=f;
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;

}

void traversal(){
    struct node *temp;
    temp=f;
    printf("TRAVERSAL\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    printf("START!\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    traversal(f);
    printf("dequed element : %d\n",dequeue(f));
    traversal(f);
    printf("END!");
    return 0;

}