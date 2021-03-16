//  doubleLinkedList
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
    struct node* prev;
};

void create(void);
void insert(struct node *);
void display(struct node *);
void delet(struct node *);

struct node *head=NULL;

int main()
{
    int n;
    printf("1.Create \t2. Insert \t3. Display \t4. Delete \t5. Exit");
    for(;;)
    {
        printf("\nEnter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: create();
                break;
            case 2: insert(head);
                break;
            case 3: display(head);
                break;
            case 4: delet(head);
                break;
            case 5: exit(0);
        }
    }
}

void create()
{
    struct node *last;
    char c;int val;
    do
    {
        printf("Enter value to be inserted: ");
        scanf("%d",&val);
        if(head==NULL)
        {
            head=(struct node *)malloc(sizeof(struct node));
            head->data=val;
            head->next=NULL;
            head->prev=NULL;
        }
        else
        {
            last=head;
            while(last->next!=NULL)
                last=last->next;
            last->next=(struct node *)malloc(sizeof(struct node));
            last->next->data=val;
            last->next->next=NULL;
            last->next->prev=last;
        }
        printf("Do you want to continue? ");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='y');
}

void insert(struct node *last)
{
    int val,pos;
    struct node *temp;
    printf("\nEnter the position at which value will be inserted: ");
    scanf("%d",&pos);
    printf("Enter value to be inserted: ");
    scanf("%d",&val);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    
    if(pos==1)
    {
        temp->next=head;
        last->prev=temp;
        head=temp;
        temp->prev=NULL;
    }
    else
    {
        pos--;
        while(pos!=1)
        {
            last=last->next;
            pos--;
        }
        if(last->next==NULL)
        {
            temp->next=last->next;
            last->next=temp;
            temp->prev=last;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
            temp->next->prev=temp;
            temp->prev=last;
        }
    }
}

void display(struct node *last)
{
    if(head==NULL)
        printf("Linked list is empty.");
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

void delet(struct node *last)
{
    int pos;
    struct node *temp;
    if(head==NULL)
        printf("List is empty.");
    else
    {
        printf("\nEnter the position of data to be deleted:");
        scanf("%d",&pos);
        if(pos==1)
        {
            head=head->next;
            free(last);
            head->prev=NULL;
        }
        else
        {
            pos--;
            while(pos!=1)
            {
                last=last->next;
                pos--;
            }
            if(last->next->next==NULL)
            {
                temp=last->next;
                printf("%d is deleted",temp->data);
                last->next=NULL;
                free(temp);
            }
            else
            {
                temp=last->next;
                printf("%d is deleted",temp->data);
                last->next=temp->next;
                free(temp);
                last->next->prev=last;
            }
        }
    }
}
