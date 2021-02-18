#include <stdio.h>    //linear queue using array
#include <stdlib.h>
#define maximum 5
void insert(void);    //function to insert values in queue
void delet(void);     //function to delete values from queue
void display(void);   //function to display values in queue
int ray[maximum],front=0,rear=-1;
int main()
{
  int n;
  printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n");
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

void insert(void)        //inserting values in queue
{
  int v;
  if(rear==(maximum-1))
    printf("\nQueue Overflow");
  else
  {
    printf("\nEnter value to be inserted:");
    scanf("%d",&v);
    rear++;
    ray[rear]=v;
  }
}

void delet()             //deleting values from queue
{
  if(front>rear)
    printf("\nQueue underflow");
  else
  {
    printf("\nThe value deleted from Queue is %d",ray[front]);
    front++;
  }
}
void display()
{
  int i;
  if(front>rear)
  printf("\nQueue empty");
  else
  {
    for(i=front;i<=rear;i++)
    {
      printf("%d\n",ray[i]);
    }
  }
}
