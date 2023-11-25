#include <math.h>
#include <stdlib.h>
#include <stdio.h>


void print(double** array, int size){
    int row = sqrt(size), col = sqrt(size) + 1;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }
}

double** create_array(int* matrix, int* vector, int size, double* p){
    int row = sqrt(size), col = sqrt(size) + 1;
    p = malloc(sizeof(double) * col * row);
    double** array = malloc(sizeof(double*) * row);
    for (int i = 0; i < row; i++){
        array[i] = p + col * i;
    }
    return array;
}

int check(double** array, int size){
    int count = 0, row = sqrt(size), col = sqrt(size) + 1;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (array[i][j] == 0) count += 1;
        }
        if (count == col) return -1;
        count = 0;
    }
    return 1;
}

void completion_array(int* matrix, int* vector, int size, double** array){
    int row = sqrt(size), col = sqrt(size) + 1;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (j == (col - 1)){
                array[i][j] = (double)vector[i];
            } 
            else{
                array[i][j] = (double)matrix[i * (col - 1) + j];
            } 
        }
    }
}

int ghost_matrix(double** array, int size){
    int row = sqrt(size), col = sqrt(size) + 1;
    int i = 0; // нынешняя строка
    int swap, number;
    for (int j = 0; j < col - 1; j++){//нынешний столбец
        for (int l = i; l < row; l++){//нахождение в столбце ненулевого значения
            if ((l == i) && array[i][j] == 1) break;
            number = array[i][j];
            if ((l == i) && (array[i][j] != 0)){
                for (int k = 0; k < col; k++){
                    array[i][k] /= number;
                }
            break;
            }
            if (array[l][i] != 0){
                number = array[i][j];
                for (int k = 0; k < col; k++){//меняем i-ю строчку с l-ой строчкой
                    swap = array[i][k];
                    array[i][k] = array[l][k] / number;
                    array[l][k] = swap;
                }// поменяли строчки  
            }
            break;
        }
        for (int l = 0; l < row; l++){//вычитаем из всех строчек i-ю строчку
            if (l == i) continue;
            int number = array[l][j];
            for (int k = 0; k < col; k++){
                array[l][k] -= number * array[i][k];
            }
        }
        if (check(array, size) == -1){
            return -1;
        }
    i++;
    }
    return 1;
}
double rez(double** array, int size){
    int row = sqrt(size), col = sqrt(size) + 1;
    double answer = 0;
    for (int i = 0; i < row; i++){
        answer += array[i][col - 1];
    }
    return answer;
}

double kramer_method(int* matrix, int* vector, int size){
    double* p;
    double** p_array = create_array(matrix, vector, size, p);
    int flag;
    completion_array(matrix, vector, size, p_array);
    flag = ghost_matrix(p_array, size);
    double answer = rez(p_array, size);
    if (flag == -1) answer = -1;
    return answer;
}

int main(){
    int a1[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int b1[] = {1, 1, 1};
    int size = 9;
    double answer = kramer_method(a1, b1, size);
    printf("%lf", answer);
}