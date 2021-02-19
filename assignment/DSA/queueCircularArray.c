#include <stdio.h>    //circular queue using array
#include <stdlib.h>
#define max 5
void insert(void);    //function to insert values in queue
void delet(void);     //function to delete values from queue
void display(void);   //function to display values in queue
int ray[max],count=0,front=0,rear=-1;
int main()
{
  int n;
  printf("1. Insert\t2. Delete\t3. Display\t4. Exit");
  for(;;)
  {
   printf("\nEnter your response:");
   scanf("%d",&n);
   switch(n)
   {
    case 1:insert();
           break;
    case 2:delet();
           break;
    case 3:display();
           break;
    case 4:exit(0);
   }
  }
 }

 void insert()     //inserting values in queue
 {
   int v;
   if(count==max)
     {
       printf("\nQueue Overflow");
     }
   else
      {
        printf("\nEnter value to be inserted:");
        scanf("%d",&v);
          rear++;
        if(rear==max)
           rear=0;
        ray[rear]=v;
       count++;
      }
 }

 void delet()      //deleting value from queue
 {
   if(count==0)
      printf("\nQueue underflow");
  else
    {
     printf("\nThe value deleted from Queue is %d",ray[front]);
     front++;
     if(front==max)
         front=0;
       count--;
    }
 }

void display()    //displaying values of queue
{
  int i;
  if(count==0)
    printf("\nQueue empty");
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
