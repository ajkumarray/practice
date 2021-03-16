//  stackUsingLinkedList
//  Created by Ajit Kumar on March15//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Linked List is a linear data structure. Unlike arrays, linked list elements are not stored at a contiguous location, the elements are linked using pointers.
 */

#include <stdio.h>     //stack using linked list
#include <stdlib.h>

struct node{              //declaration of node
    int data;
    struct node* next;
};

void push(void);                //push function
void pop(void);                 //pop function
void display(struct node *);    //display function

struct node *head=NULL;

int main()
{
    int n;
    printf("1. Push \t2. Pop \t3. Display \t4. Exit");
    for(;;)
    {
        printf("\nEnter your response:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push();         //function to push values in stack
                break;
            case 2: pop();          //function to pop/delete values from stack
                break;
            case 3: display(head);  //function to display elements of stack
                break;
            case 4: exit(0);
        }
    }
}

void push()
{
    struct node *last;
    int val;
    printf("Enter value to be inserted:");
    scanf("%d",&val);
    if(head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->data=val;
        head->next=NULL;
    }
    else
    {
        last=head;
        while(last->next!=NULL)
            last=last->next;
        last->next=(struct node *)malloc(sizeof(struct node));
        last->next->data=val;
        last->next->next=NULL;
    }
}

void display(struct node *last)
{
    if(head==NULL)
        printf("Stack is empty.");
    else
    {
        while(last!=NULL)
        {
            printf("%d->",last->data);
            last=last->next;
        }
        printf(" END");
    }
}

void pop()
{
    struct node *temp;
    if(head==NULL)
        printf("Stack underflow");
    else
    {
        if(head->next==NULL)
        {
            printf("%d is deleted",head->data);
            head=NULL;
        }
        else
        {
            temp=head;
            while(temp->next->next!=NULL)
                temp=temp->next;
            printf("%d is deleted",temp->next->data);
            free(temp->next);
            temp->next=NULL;
        }
    }
}
