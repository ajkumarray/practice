#include <stdio.h>    //stack using array
#include <stdlib.h>
void push(void);      //function to push values in stack
void pop(void);       //function to delete values from stack
void display(void);   //function to display values in stack
#define max 5
int ray[max],top=-1;
int main()
{
    int n;
    printf("1. Push\t2. Pop\t3. Display\t4. Exit");
    for(;;)
    {
        printf("\nEnter your response:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            case 4:exit(0);
        }
    }
}
void push(void)
{
    int v;
    if(top==(max-1))
        printf("Stack Overflow.");
    else
    {
        printf("Enter value to be pushed:");
        scanf("%d",&v);
        top++;
        ray[top]=v;
    }
}
void pop(void)
{
    if(top==-1)
        printf("Stack Underflow.");
    else
    {
        printf("The value deleted from stack is:%d",ray[top]);
        top--;
    }
}
void display(void)
{
    int i;
    if(top==-1)
        printf("Stack Empty.");
    else
    {
        for(i=0;i<=top;i++)
            printf("%d\n",ray[i]);
    }
}

