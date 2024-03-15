#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

int main()
{
    struct queue q;
    initialize_queue(&q);
    int ch;
    int ele;

    while(1)
    {
        printf("1.insert\n");
        printf("2.dequeue\n");
        printf("3.display\n");

        printf("Enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:if(isFull(q))
                  {
                      printf("queue over flow\n");
                  }
                  else
                    {
                        printf("Enter elements:");
                        scanf("%d",&ele);
                        insert(&q,ele);
                    }
                    break;

              case 2:if(isEmpty(q))
                     {
                       printf("queue under flow\n");
                       return -1;
                     }
                     else
                     {
                         ele=dequeue(&q);
                         printf("the deleted item is ele\n");
                     }
                     break;

              case 3:display(&q);
                     break;
        }
      }
    }
    void initialize_queue(struct queue *q)
    {
        q->front=0;
        q->rear=-1;
    }
    void insert(struct queue *q,int ele)
    {
        q->rear++;
        q->items[q->rear]=ele;
    }
    int isFull(struct queue *q)
    {
        if(q->rear==MAX_SIZE-1)
            return 1;
        return 0;
    }
    int dequeue(struct queue *q)
    {
        int ele;
        ele=q->items[q->front];
        q->front++;
        return ele;
    }
    int isEmpty(struct queue *q)
    {
        if((q->rear==-1)||(q->front>q->rear))
            return 1;
        return 0;
    }
    void display(struct queue *q)
    {
        int i;
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\n");
        }
    }
