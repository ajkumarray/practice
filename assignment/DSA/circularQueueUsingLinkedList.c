//  circularQueueUsingLinkedList
//  Created by Ajit Kumar on March15//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Linked List is a linear data structure. Unlike arrays, linked list elements are not stored at a contiguous location, the elements are linked using pointers.
 */

#include <stdio.h>
#include <stdlib.h>

struct node{              //declaration of node
    int data;
    struct node* next;
};

void insert(void);
void delet(void);
void display(struct node *);

struct node *head=NULL;

int main()                //main function
{
    int n;
    printf("1. Insert \t2. Delete \t3. Display \t4. Exit");
    for(;;)
    {
        printf("\nEnter your response:");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insert();
                break;
            case 2: delet();
                break;
            case 3: display(head);
                break;
            case 4: exit(0);
        }
    }
}

void insert()                 //function to insert elements in queue
{
    struct node *last,*temp;
    int val;
    printf("Enter value to be inserted:");
    scanf("%d",&val);
    if(head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->data=val;
        head->next=head;
    }
    else
    {
        last=head;
        while(last->next!=head)
            last=last->next;
        temp=(struct node *)malloc(sizeof(struct node));
        last->next=temp;
        temp->data=val;
        temp->next=head;
    }
}

void display(struct node *last)       //function to display elements of queue
{
    if(head==NULL)
        printf("Queue is empty.");
    else
    {
        do
        {
            printf("%d->",last->data);
            last=last->next;
        }
        while(last!=head);
        printf(" END");
    }
}

void delet()                        //function to delete elements of queue
{
    struct node *temp,*last;
    if(head==NULL)
        printf("Queue underflow");
    else
        if(head->next==head)
        {
            printf("%d is deleted",head->data);
            head=NULL;
        }
    else
    {
        temp=head;
        last=head;
        printf("%d is deleted",head->data);
        while(last->next!=head)
            last=last->next;
        head=head->next;
        last->next=head;
        free(temp);
    }
}
