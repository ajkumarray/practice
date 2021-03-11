//  fractionalKnapsackCPP
//  Created by Ajit Kumar on March10//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Given weights and values of n items, we need to put these items in a knapsack of capacity w to get the maximum total value in the knapsack.
 In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
 
 The basic idea is to calculate the ratio value/weight for each item and sort the item on basis of this ratio.
 Then take the item with the highest ratio and add them until we can't add the next item as a whole and at the end add the next item as much as we can.
 Which will always be the optimal solution to this problem.
 */

#include <bits/stdc++.h>
using namespace std;

struct Item
   {            //structure for an item which stores weight and corresponding value of item
       int value, weight;
   };

bool cmp(struct Item a,struct Item b)
{           //comparison function to sort item according to value/weight
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, struct Item ray[], int n)
{
    sort(ray, ray + n, cmp);        //sorting item on basis of ratio
    int curWeight = 0;              //current weight of knapsack
    double finalvalue = 0.0;        //result value in knapsack
    for(int i=0;i<n;i++)            //looping through all items
    {       //if adding items won't overflow, add it completely
        if(curWeight + ray[i].weight <= w)
        {
            curWeight += ray[i].weight;
            finalvalue += ray[i].value;
        }
        else {      //if we can't add current item, add fractional part of it
            int remain = w - curWeight;
            finalvalue += ray[i].value * ((double)remain / (double)ray[i].weight);
            break;
        }
    }
    return finalvalue;              //returning final value
}

int main(int argc, const char * argv[]) {
    int n,w;                        //n is number of item and w is max weight knapsack can hold
    cout << "Enter number of items and max weight sack can contain: ";
    cin >> n >> w;
    
    struct Item ray[n];
    cout << "Enter value and weight of each item." << endl;
    for(int i=0;i<n;i++)
    {
        cout << "For Item " << (i+1) << " : ";
        cin >> ray[i].value >> ray[i].weight;
    }
    cout << "Maximum value we can obtain = " << fractionalKnapsack(w, ray, n);      //function call
    return 0;
}

/*
 As main time taking step is sorting, the whole problem can be solved in O(n log n) only.
 */
