#include <stdio.h>


int fibonachi(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonachi(n - 1) + fibonachi(n - 2);

}

int fibonachi2(int n){
    int first = 0, second = 1, sum = 0;
    if (n == 1) return 1;
    for (int i = 2; i <= n; i++){
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonachi(n));
    printf("%d", fibonachi2(n));
}