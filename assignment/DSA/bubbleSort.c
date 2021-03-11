//  bubbleSort
//  Created by Ajit Kumar on March12//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
 Worst and Average case Time Complexity: O(n^2). Worst case occures when array is reverse sorted.
 Best case Time Complexity: O(n). Best casse occurs when array is already sorted.
 */

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int ray[],int n)         //function to sort an array using bubble sort
{
    for(int i=0;i<n-1;i++)
    {
        int swap = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(ray[j] > ray[j+1])
            {
                int temp = ray[j];
                ray[j] = ray[j+1];
                ray[j+1] = temp;
                swap = 1;
            }
        }
        if(swap == 0)           //if no two elements are swapped by inner loop, then break
            break;
    }
}

void printArrray(int ray[],int n)           //function to print array
{
    for(int i=0;i<n;i++)
        printf("%d ",ray[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    int ray[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&ray[i]);
    bubbleSort(ray, n);
    printf("Sorted in ascending order: ");
    printArrray(ray, n);
    return 0;
}
