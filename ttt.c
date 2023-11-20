#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* myrandom(int size){
    srand(time(NULL));
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
        array[i] = 0;
    }
    int i = 0, index1, index2, number;
    while(i < size - 1){
        index1 = rand() % (size);
        index2 = rand() % (size);
        number = 1 + rand() % 1000;
        while ((array[index1] != 0) || (array[index2] != 0) || (index1 == index2)){
            index1 = rand() % (size);
            index2 = rand() % (size);
        }
        array[index1] = number;
        array[index2] = number;
        i += 2;
    }
    i = 0;
    while (array[i] != 0){
        i++;
    }
    array[i] = rand() % 1001;
    return array;
}

int find_elem(int* array, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum ^= array[i];
    }
    return sum;
}

int main(){
    int size;
    printf("enter size ");
    scanf("%d", &size);
    int* array2 = myrandom(size);
    int otvet = find_elem(array2, size);
    for (int i = 0; i < size; i++){
        printf("%d ", array2[i]);
    }
    printf("\n%d", otvet);
}