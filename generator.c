#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void max_min(int* array, int k, int m, int f){
    srand(time(NULL));
    int max = 0, min = 1;
    while ((max - min != f) || (max < min)){
        max = rand() % k/2;
        min = rand() % (k/4);
    }
    array[0] = min;
    array[1] = max;
}

int check(int* array, int* real_size, int m, int k){
    int sum = 0;
    for (int i = 0; i < *real_size; i++){
        sum += array[*real_size];
    }
    if ((sum < k) && (sum > m)) return 1;
    return 0;
}

void geterator(int* array, int* real_size, int k, int m){
    srand(time(NULL));
    k = (k - array[0] - array[1]);
    int flag = 1;
    while (flag != 1){
        for (int i = 2; i < *real_size - 2; i++){
            array[*real_size] = (array[0] + 1) + rand() % (array[1] - array[0] - 1);
        }
        flag = check(array, real_size, m, k);
    }
    
}


int* array_generator(int* real_size, int k, int m, int f){
    *real_size = 10 + rand() % 91;
    int* array = malloc(sizeof(int) * *real_size);
    man_min(array, k, m, f);
    generator(array, real_size, k, m);
    return array;
}

int main(){
    int* real_size;
    int k, m, f;
    int* array = array_generator(real_size, k, m, f);
    for (int i = 0; i < *real_size; i++){
        printf("%d ", array[i]);
    }
}
