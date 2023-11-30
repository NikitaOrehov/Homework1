#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

bool check_function(int* arr, int size, int K, int M, int F){
    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    for (int i = 1; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    return (sum <= K && sum >= M && abs(max-min) == F);
}

int* create_array(int *real_size, int number){
    int* array = malloc(sizeof(int) * *real_size);
    for (int i = 0; i < *real_size; i++){
        array[i] = number;
    }
    return array;

}

int main(){
    int k = 100, m = 10, f = 50;
    int* real_size = malloc(sizeof(int));
    int flag = 1, number = 0, difference = 0;
    int* array;
    while (flag){
        for (int i = 10; i < k + 1; i++){
            if (k % i == 0){
                flag = 0;
                *real_size = i;
                break;
            }
        }
        number = k / *real_size;
        if (flag == 1){
            k--;
            continue;
        }
        array = create_array(real_size, number);
        if (f % 2 == 0){
            array[0] -= f/2;
            array[1] += f/2;
        }
        else{
            array[0] -= f/2 - 1;
            array[1] += f/2;
        }
    }
    printf("\n%d", check_function(array, *real_size, k, m, f));
    return 0;
}
