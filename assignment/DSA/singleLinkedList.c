//  single linked list

//  Created by Ajit Kumar on October12//2020 AD.
//  Copyright © 2020 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

struct node{            //node definition
    int data;
    struct node* next;
};
 
void create(void);
void insert(struct node *);
void display(struct node *);
void delet(struct node *);
void reverse(void);
void sort(struct node *);
void search(struct node *);

struct node *head=NULL;

int main()
{
    int n;
    printf("1.Create \t2. Insert \t3. Display \t4. Delete \t5. Reverse \t6. Sort \t7. Search \t8. Exit");
    for(;;)
    {
        printf("\nEnter your response:");
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
            case 5: reverse();
                break;
            case 6: sort(head);
                break;
            case 7: search(head);
                break;
            case 8: exit(0);
        }
    }
}

void create()           //to create a list
{
    struct node *last;
    char c;int val;
    do
    {
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
        printf("Do you want to continue?");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='y');
}

void insert(struct node *last)              //to insert values in list on a specific position
{
    int val,pos; //int i;
    struct node *temp;
    printf("\nEnter the position at which value will be inserted:");
    scanf("%d",&pos);
    printf("Enter value to be inserted:");
    scanf("%d",&val);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    
    if(pos==1)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        pos--;
        while(pos!=1)
        {
            last=last->next;
            pos--;
        }
        temp->next=last->next;
        last->next=temp;
    }
}

void display(struct node *last)         //to display existing values in list
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

void delet(struct node *last)           //to delete values from list from a specific position
{
    int pos;
    struct node *temp;
    if(head==NULL)
        printf("List is empty");
    else
    {
        printf("\nEnter the position of data to be deleted:");
        scanf("%d",&pos);
        if(pos==1)
        {
            printf("%d is deleted",head->data);
            head=head->next;
            free(last);
        }
        else
        {
            pos--;
            while(pos!=1)
            {
                last=last->next;
                pos--;
            }
            temp=last->next;
            printf("%d is deleted",temp->data);
            last->next=last->next->next;
            free(temp);
        }
    }
}

void reverse()                  //to reverse the order of values in list
{
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    printf("List is reversed.");
}

void sort(struct node *last)            //to sort the list in ascending order
{
    struct node *temp=NULL;
    int t;
    while(last->next!=NULL)
    {
        temp=last->next;
        while(temp!=NULL)
        {
            if(last->data>temp->data)
            {
                t=last->data;
                last->data=temp->data;
                temp->data=t;
            }
            temp=temp->next;
        }
        last=last->next;
    }
    printf("List is sorted in ascending order.");
}

void search(struct node *last)          //to search a specific value in list
{
    int pos=1,val,flag=0;
    printf("Enter value to be searched:");
    scanf("%d",&val);
    while(last!=NULL)
    {
        if(last->data==val)
        {
            printf("Found %d at position %d",val,pos);
            flag++;
        }
        last=last->next;
        pos++;
    }
    if(flag==0)
        printf("Not found");
}
