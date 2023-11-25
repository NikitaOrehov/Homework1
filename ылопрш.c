#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int** array_creation(int row, int col){
    int* p = (int*)malloc(sizeof(int) * row * col);
    int** q = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++){
        q[i] = p + col * i;
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            q[i][j] = j;
        }
    }
    return q;
    
}

int main(){
    int** p;
    int row, col;
    printf("row = ");
    scanf("%d", &row);
    printf("column = ");
    scanf("%d", &col);
    p = array_creation(row, col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}