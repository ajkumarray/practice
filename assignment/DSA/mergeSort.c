//  mergeSort
//  Created by Ajit Kumar on March08//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

void merge(int ray[],int low,int mid,int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i] = ray[low+i];
    for(int j=0;j<n2;j++)
        R[j] = ray[mid+1+j];
    
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            ray[k] = L[i];
            i++;
        }
        else
        {
            ray[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        ray[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        ray[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int ray[],int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(ray,low,mid);
        mergeSort(ray,mid+1,high);
        merge(ray,low,mid,high);
    }
}
void printArray(int ray[],int n)
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
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&ray[i]);
    
    printf("Given array is:\n");
    printArray(ray,n);
    
    mergeSort(ray,0,n-1);
    
    printf("Sorted array is:\n");
    printArray(ray,n);
    
    return 0;
}
