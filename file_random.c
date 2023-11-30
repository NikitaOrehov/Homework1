#include <stdio.h>
#include <stdlib.h>


double* create_array(int size){
    double* array = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++){
        array[i] = 10000 * (double)rand() / RAND_MAX;
    }
    return array;
}

void file1(FILE* p_f, double* array, int size){
    fprintf(p_f, "%d\n", size);
    for (int i = 0; i < size; i++){
        fprintf(p_f, "%lf\n", array[i]);
    }
}

double* file2(FILE* p_f, int* size){
    fscanf(p_f, "%d\n", size);
    double* p_array = malloc(sizeof(double*) * *size); 
    for (int i = 0; i < *size; i++){
        fscanf(p_f, "%lf\n", &p_array[i]);
    }
    return p_array;
}

int main(){
    int size;
    printf("Enter size = ");
    scanf("%d", &size);
    double* p_array = create_array(size);
    FILE* p_f = fopen("file.txt", "w");
    file1(p_f, p_array, size);
    size = 0;
    free(p_array);
    fclose(p_f);
    p_f = fopen("file.txt", "r");
    double* new_array = file2(p_f, &size);
    fclose(p_f);
    printf("%d\n", size);
    for (int i = 0; i < size; i++){
        printf("%lf\n", new_array[i]);
    }

}