//binary search
/*
 binary search is a fast search algorithm with run-time complexity of O(log n). This search algorithm works on the principle of divide and conquer. For this algo to work properly,the data collection should be in the sorted form.

Binary search looks for a particular item by comparing the middle most item of the collection. If a match occurs, then the index of item is returned. If the middle item is greater than the item, then the item is searched in the sub-array to the left of the middle item. Otherwise, the item is searched for in the sub-array to the right of the middle item. This process continues on the sub-array as well untill the size of the sub-array reduces to zero.
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,num,i,beg,end,mid;
    printf("How many numbers:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number to be searched:");
    scanf("%d",&num);
    (beg=0);end=n-1;
    mid=(beg+end)/2;
    while(num!=a[mid] && beg<=end) {
        if(num>a[mid]) {
            beg=mid+1;
        }
        if(a[mid]>num)
            end=mid-1;
        mid=(beg+end)/2;
    }
    if(num == a[mid])
        printf("Found at %d position",mid+1);
    else
        printf("Not found");
    return 0;
}
