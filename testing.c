#include <math.h>
#include <stdio.h>

int razbienie(int matrix[], int leng, int number);

int main(){
    int matrix[36] = {1, 0, 0, 0, 0, 5, 5, 5, 5, 5, -1, -1, -2, -1, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, size = 36;
    int leng = sqrt(size);
    int sum = 0;
    if (leng * leng != size) return -404;
    if (leng == 2) return (matrix[0] * matrix[3] - matrix[1] * matrix[2]);
    for (int i = 0; i < leng; i++){
        if (i % 2 == 0){
            sum += matrix[i] * razbienie(matrix, leng, i);
        }
        else {
            sum -= matrix[i] * razbienie(matrix, leng, i);
            }
    }
    printf("%d", sum);
}

int razbienie(int matrix[], int leng, int number){
    int mini_matrix[100], count = 0;
        for (int k = 1; k < leng; k++){
            for (int h = 0; h < leng; h++){
                if (k * leng + number == k * leng + h);
                else{
                mini_matrix[count] = matrix[k * leng + h];
                count += 1;
                }
            }
        }
        leng = leng - 1;

        if (leng > 2){
            int mini_sum = 0;
            for (int l = 0; l < leng; l++){
                if (l % 2 == 0){
                    mini_sum += mini_matrix[l] * razbienie(mini_matrix, leng, l);
                }
                else {
                    mini_sum -= mini_matrix[l] * razbienie(mini_matrix, leng, l);
                } 
            }
            return mini_sum;
        }
        else{
            return ((mini_matrix[0] * mini_matrix[3] - mini_matrix[1] * mini_matrix[2]));
        }
}