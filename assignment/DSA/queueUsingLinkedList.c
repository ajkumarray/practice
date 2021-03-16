//  queueUsingLinkedList
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

int main()
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

void insert()
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
        printf("Queue is empty.");
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

void delet()
{
    struct node *temp;
    if(head==NULL)
        printf("Queue underflow");
    else
    {
        temp=head;
        printf("%d is deleted",head->data);
        head=head->next;
        free(temp);
    }
}
