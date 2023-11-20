#include <math.h>
#include <stdio.h>


int sort(int array[], int size){
    int p = 0;
    for (int i = 0; i < size - 1; i++){
        for (int j = size - 1; j > i; j--){
            if (array[j] < array[j - 1]){
                p = array[j];
                array[j] = array[j - 1];
                array[j - 1] = p;
            }
        }
    }
}




int main(){
    int size = 5;
    int array[5] = {4, 7, 9, 1, 3};
    sort(array, size);
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }

}