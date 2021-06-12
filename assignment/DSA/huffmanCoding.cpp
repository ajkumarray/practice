//  huffman
//  Created by Ajit Kumar on April21//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Huffman is a lossless data compression algorithm. In this algorithm, a variable-length code is assigned to input different characters.
 The code length is related to how frequently characters are used. Most frequent characters have the smallest codes and longer codes for least frequent characters.
 There are mainly two parts. First one to create a Huffman tree, and another one to traverse the tree to find codes.
 
 Complexity for assigning the code for each character according to their frequency is O(n log n).
 
 *** Steps to build Huffman Tree ***
 Input is an array of unique characters along with their frequency of occurrences and output is Huffman Tree.
 
 1. Create a leaf for each unique characters and build a min heap of all leaf nodes.
 2. Extract two nodes with the minimum frequency from the min heap.
 3. Create a new internal node with a frequency equal to the sum of the two nodes frequencies.
    Make the first extracted node as its left child and the other extracted node as its right child.
    Add this node to the min heap.
 4. Repeat steps #2 and #3 untill the heap contains only one node. The remaining node is the root node and the tree is complete.
 
 *** Example ***
 Character      Frequency
    a               5
    b               9
    c               12
    d               13
    e               16
    f               45
 
 Step 1: Build a min heap that contains 6 nodes where each node represents root of a tree with single node.
 Step 2: Extract two minimum frequency nodes from min heap. Add a new internal nodde with frequency 5+9=14.
 
        14
       /  \
    a|5   b|9
 
 Now min heap contains 5 nodes
 */


//  huffmanCoding
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct heapNode
{
    char data;
    unsigned frequency;
    struct heapNode *left, *right;
};

struct minHeap
{
    unsigned size;
    unsigned capacity;
    struct heapNode** array;
};

struct heapNode* newNode(char data, unsigned frequency)
{
    struct heapNode* temp = (struct heapNode*)malloc(sizeof(struct heapNode));
    
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    
    return temp;
}

struct minHeap* createMinHeap(unsigned capacity)
{
    struct minHeap* mHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    
    mHeap->size = 0;
    mHeap->capacity = capacity;
    mHeap->array = (struct heapNode**)malloc(mHeap->capacity * sizeof(struct heapNode*));
    return mHeap;
}

void swapHeapNode(struct heapNode** a, struct heapNode** b)
{
    struct heapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct minHeap* mHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if(left < mHeap->size && mHeap->array[left]->frequency < mHeap->array[smallest]->frequency)
        smallest = left;
    
    if(right < mHeap->size && mHeap->array[right]->frequency < mHeap->array[smallest]->frequency)
        smallest = right;
    
    if(smallest != idx)
    {
        swapHeapNode(&mHeap->array[smallest], &mHeap->array[idx]);
        minHeapify(mHeap, smallest);
    }
}

int isSizeOne(struct minHeap* mHeap)
{
    return (mHeap->size == 1);
}

struct heapNode* extractMin(struct minHeap* mHeap)
{
    struct heapNode* temp = mHeap->array[0];
    mHeap->array[0] = mHeap->array[mHeap->size - 1];
    
    --mHeap->size;
    minHeapify(mHeap, 0);
    
    return temp;
}

void insertMinHeap(struct minHeap* mHeap, struct heapNode* minHeapNode)
{
    ++mHeap->size;
    int i = mHeap->size - 1;
    
    while(i && minHeapNode->frequency < mHeap->array[(i - 1) / 2]->frequency)
    {
        mHeap->array[i] = mHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    mHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct minHeap* mHeap)
{
    int n = mHeap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i)
        minHeapify(mHeap, i);
}

void printArray(int ray[], int n)
{
    int i;
    for(i = 0; i < n; ++i)
        printf("%d", ray[i]);
    printf("\n");
}

int isLeaf(struct heapNode* root)
{
    return !(root->left) && !(root->right);
}

struct minHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct minHeap* mHeap = createMinHeap(size);
    
    for(int i = 0; i < size; i++)
        mHeap->array[i] = newNode(data[i], freq[i]);
    
    mHeap->size = size;
    buildMinHeap(mHeap);
    
    return mHeap;
}

struct heapNode* buildHuffmanTree(char data[], int frequency[], int size)
{
    struct heapNode *left, *right, *top;
    struct minHeap* mHeap = createAndBuildMinHeap(data, frequency, size);
    
    while(!isSizeOne(mHeap))
    {
        left = extractMin(mHeap);
        right = extractMin(mHeap);
        
        top = newNode('$', left->frequency + right->frequency);
        
        top->left = left;
        top->right = right;
        
        insertMinHeap(mHeap, top);
    }
    return extractMin(mHeap);
}

void printCodes(struct heapNode* root, int ray[], int top)
{
    if(root->left)
    {
        ray[top] = 0;
        printCodes(root->left, ray, top + 1);
    }
    
    if(root->right)
    {
        ray[top] = 1;
        printCodes(root->right, ray, top + 1);
    }
    
    if(isLeaf(root))
    {
        printf("%c: ",root->data);
        printArray(ray,top);
    }
}

void huffmanCode(char data[], int freq[], int size)
{
    struct heapNode* root = buildHuffmanTree(data, freq, size);
    int ray[MAX_TREE_HT], top = 0;
    printCodes(root, ray, top);
}

int main()
{
    int size;
    printf("Enter number of unique characters: ");
    scanf("%d",&size);
    char ray[size];
    int freq[size];
    for(int i = 0; i < size; i++)
    {
        printf("Enter character and their frequency: ");
        scanf("%s%d", &ray[i],&freq[i]);
    }
    huffmanCode(ray, freq, size);
    
    return 0;
}
