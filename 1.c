#include <stdio.h>

int main(){
    double a, b;
    printf("first programm\nenter a and b  ");
    scanf("%lf %lf", &a, &b);
    printf("a + b = %.1lf\na - b = %.1lf\na * b = %.1lf\na / b = %.2lf\n\n\n", a + b, a - b, a * b, a / b);
    return 0;
}