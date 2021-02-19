//deque using array
#include<stdio.h>
#include<stdlib.h>
#define max 5
void insert_front(void);         //function to insert values in queue from front
void insert_rear(void);        //function to insert values in queue from rear
void delete_front(void);         //function to delete values from queue from front
void delete_rear(void);        //function to delete values from queue from rear
void display(void);             //function to display values in queue
int ray[max],front=0,rear=-1,count=0;
int main()
{
    int n;
    printf("1. Insert from Front \t 2. Insert from Rear \t 3. Delete from Front \t 4. Delete from Rear \t 5. Display \t 6. Exit");
    for(;;)
    {
        printf("\nEnter your response:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insert_front();
                break;
            case 2:insert_rear();
                break;
            case 3:delete_front();
                break;
            case 4:delete_rear();
                break;
            case 5:display();
                break;
            case 6:exit(0);
        }
    }
}

void insert_front(void)          //inserting values from front
{
    int i,v;
    if(count==max)
        printf("\nQueue Overflow");
    else
    {
        if(rear>=front)
        {
            for(i=rear;i>=front;i--)
                if(i==(max-1))
                    ray[0]=ray[i];
                else
                    ray[i+1]=ray[i];
        }
        if(front>rear)
        {
            for(i=rear;i>=0;i--)
                ray[i+1]=ray[i];
            ray[0]=ray[max-1];
            for(i=max-1;i>front;i--)
                ray[i]=ray[i-1];
        }
        printf("\nEnter the value to be inserted from front:");
        scanf("%d",&v);
        ray[front]=v;
        rear++;
        count++;
    }
}

void insert_rear(void)             //inserting value from rear
{
    int v;
    if(count==max)
        printf("\nQueue is overflow.");
    else
    {
        printf("\nEnter value to inserted from rear:");
        scanf("%d",&v);
        rear++;
        if(rear==max)
            rear=0;
        ray[rear]=v;
        count++;
    }
}

void delete_front(void)          //deleting value from front
{
    if(count==0)
        printf("\nQueue Underflow");
    else
    {
        printf("The value deleted from front of queue is %d",ray[front]);
        front++;
        if(front==max)
            front=0;
        count--;
    }
}

void delete_rear(void)         //deleting value from rear
{
    if(count==0)
        printf("\nQueue Underflow");
    else
    {
        printf("\nThe value deleted from rear of Queue is %d",ray[front]);
        front++;
        if(front==max)
            front=0;
        count--;
    }
}

void display(void)          //displaying values in queue
{
    int i;
    if(count==0)
        printf("\nQueue Empty");
    else
    {
        if(front<=rear)
            for(i=front;i<=rear;i++)
                printf("\n%d",ray[i]);
        else
        {
            for(i=front;(i<=max-1);i++)
                printf("\n%d",ray[i]);
            for(i=0;i<=rear;i++)
                printf("\n%d",ray[i]);
        }
    }
}
