//  fractionalKnapsack
//  C program to solve Fractional Knapsack problem
//  Created by Ajit Kumar on March09//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack.
 In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
 
 The basic idea is to calculate the ratio value/weight for each item and sort the item on basis of this ratio.
 Then take the item with the highest ratio and add them until we can't add the next item as a whole and at the end add the next item as much as we can.
 Which will always be the optimal solution to this problem.
 */

#include <stdio.h>
#include <stdlib.h>

struct Item {               //structure for an item which stores weight and corresponding value of Item
    int value, weight;
};

int compare(struct Item a,struct Item b)
{                       //comparison function to sort Item according to value/weight ratio
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    if(r1 < r2)
        return 1;
    else
        return -1;
}

void printItem(struct Item ray[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Value%d = %d and weight%d = %d\n",(i+1),ray[i].value,(i+1),ray[i].weight);
    }
}

void sort(struct Item ray[],int n)      //bubble sort to sort Item according to value/weight ratio
{
    for(int i=0;i<n;i++)
    {
        struct Item temp = {0,0};       //temp struct Item
        for(int j=0;j<n-i-1;j++)
        {
            if(compare(ray[j],ray[j+1]) == 1)       //compare function to check conditions for sorting
            {
                temp = ray[j];
                ray[j] = ray[j+1];
                ray[j+1] = temp;
            }
        }
    }
}

double fractionalKnapsack(int w, struct Item ray[], int n)
{
    sort(ray,n);                            //sorting Item on basis of ratio
    printf("Item list after sorting:\n");
    printItem(ray, n);                      //printing sorted Item list
    int curWeight =0;                       //current weight of knapsack
    double finalvalue = 0.0;                //final value of knapsack
    for(int i=0;i<n;i++)                    //looping through all Items
    {
        if(curWeight + ray[i].weight <= w)  //if adding Item won't overflow, add it completely
        {
            curWeight += ray[i].weight;
            finalvalue += ray[i].value;
        }
        else                                //if we can't add current Item, add fractional part of it
        {
            int remain = w - curWeight;
            finalvalue += ray[i].value * ((double)remain / (double)ray[i].weight);
            break;
        }
    }
    return finalvalue;                    //returning final value
}

int main(int argc, const char * argv[]) {
    int n;                                //number of items
    int w;                                //max weight knapsack can hold
    printf("Enter number of items and max weight knapsack can hold: ");
    scanf("%d %d",&n,&w);
    
    struct Item ray[n];
    for(int i=0;i<n;i++)                    //reading values and weight of Items
    {
        printf("Enter value and weight of Item %d: ",i+1);
        scanf("%d %d",&ray[i].value,&ray[i].weight);
    }
    printf("Entered Item list:\n");
    printItem(ray, n);                                              //printing entered Item list
    double finalvalue = fractionalKnapsack(w, ray, n);              //function call
    printf("Maximum value we can obtain = %.2f",finalvalue);
    return 0;
}

/*
As main time taking step is sorting, the whole problem can be solved in O(n log n) only.
*/
