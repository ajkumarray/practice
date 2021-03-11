//  insertionSort
//  Created by Ajit Kumar on March12//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 In insertion sort the array is virtually split into a sorted and an unsorted part.
 Values from the unsorted part are picked and placed at the correct position in the sorted part.
 
 Algorithm: ---
 To sort an array of size n in ascendng order:
    1: Iterate from ray[1] to ray[n] over the array
    2: Compare the current element (temp) to its predecessor.
    3: If the temp element is smaller than its predecessor, compare it to the elements before.
        Move the greater elements one position up to make space for thr swapped elements.
 Time Complexity: O(n^2) {worst and average case}
 */

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int ray[],int n)         //function to sort an array using insertion sort
{
    for(int i=0;i<n;i++)
    {
        int temp = ray[i];
        int j = i-1;
        while(temp < ray[j] && j >= 0)
        {                   //move elements of ray[0..i-1], that are greater than temp, to one position ahead of their current position
            ray[j+1] = ray[j];
            j--;
        }
        ray[j+1] = temp;
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
    insertionSort(ray, n);
    printf("Sorted in ascending order: ");
    printArrray(ray, n);
    return 0;
}
