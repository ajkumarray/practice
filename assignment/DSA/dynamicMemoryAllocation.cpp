//  dynamicProgramming
/*
Dynamic Memory allocation can be defined as a procedure in which the size of a data structure is changed during the runtime.
 
malloc(): It is used to dynamically allocate a single large block of memory with the specified size.
 
calloc(): It is used to dynamically allocate the specified number of blocks of memory of the specified type. It initializes each block with a default value '0'.
 
**If space is insufficient, allocation fails and returns a NULL pointer (in both malloc and calloc).
 
free(): It is used to dynamically de-allocate the memory. The memory allocated using functions malloc() and calloc() are not de-allocated on their own. Hence the free() method is used.
 
realloc(): It is used to dynamically change the memory allocation of a previously allocated memory.
 
new() and delete() are two extra keywords for dynamic memory.
 
** All dynamically allocated variables are placed in the heap space and thus they have program-lifetime.
*/
//  Created by Ajit Kumar on February22//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int* ray;
    ray = (int*)malloc(5*sizeof(int));      //5*4 bytes = 20 bytes
    //malloc allocate the memory of 5 integers containing garbage value
    
    free(ray);
    //deallocates memory previously allocated by malloc() function
    
    ray = (int*)calloc(5, sizeof(int));
    //calloc() allocate the memory for 5 integers and set them 0 to all of them
    
    ray = (int*)realloc(ray, 10 * sizeof(int));
    //dynamically re-allocate memory using realloc()
    
    free(ray);          //deallocates memory previously allocated by calloc() function
    
    int* p = NULL;      //pointer initialization to null
    p = new(nothrow) int(10);
    //allocating block of memory for variable using new operator
    
    int *q = new(nothrow) int[5];
    //requesting block of memory of size 5
    
    for(int i=0;i<5;i++)
        q[i]=i+1;           //initializing block of memory
    
    for(int i=0;i<5;i++)
        cout<<q[i]<<" ";        //printing values from block of memory
    
    delete p;
    delete[] q;
    //freed the allocated memory
    cout<<"all good"<<endl;
    return 0;
}
