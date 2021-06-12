//  sparseMatrix
//  Created by Ajit Kumar on May31//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    int rowPos;
    int colPos;
    struct Node *next;
};

void createNode(struct Node** start, int nonZero, int rowIndex, int colIndex)
{
    struct Node *temp, *r;
    temp = *start;
    if(temp == NULL)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->value = nonZero;
        temp->rowPos = rowIndex;
        temp->colPos = colIndex;
        temp->next = NULL;
        *start = temp;
    }
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        
        r = (struct Node *)malloc(sizeof(struct Node));
        r->value = nonZero;
        r->rowPos = rowIndex;
        r->colPos = colIndex;
        r->next = NULL;
        temp->next = r;
    }
}

void PrintList(struct Node* start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;
    
    printf("Row position: ");
    while(temp != NULL)
    {
        printf("%d ", temp->rowPos);
        temp = temp->next;
    }
    printf("\n");
    
    printf("Column position: ");
    while(r != NULL)
    {
        printf("%d ", r->colPos);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while(s != NULL)
    {
        printf("%d ",s->value);
        s = s->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int row, col;
    printf("Enter number of rows and columns: ");
    scanf("%d %d",&row, &col);
    int ray[row][col];
    printf("Enter the sparse matrix:\n");
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            scanf("%d", &ray[i][j]);
    
    struct Node* start = NULL;
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(ray[i][j] != 0)
                createNode(&start, ray[i][j], i, j);
    PrintList(start);
    return 0;
}
