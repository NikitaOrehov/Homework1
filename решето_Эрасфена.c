#include <stdio.h>
#include <stdlib.h>


int* cale(int n){
    int* p_array = malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++){
        p_array[i] = i;
    }
    for (int i = 2; i <= n; i++){
        if (p_array[i] != -1){
            for (int j = i + i; j <= n; j += i){
                p_array[j] = -1;
            }
        }
    }
    for (int i = 2; i <= n; i++){
        if (p_array[i] != -1){
            printf("%d ", p_array[i]);
        }
    }
    free(p_array);
}

int main(){
    int n;
    scanf("%d", &n);
    cale(n);
}