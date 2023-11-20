#include <stdio.h>
#include <math.h>
   
int main(){
    double a,b;   
    printf("second programm\nenter a and b  ");
    scanf("%lf %lf", &a, &b);
    double srednee = (pow(a, 2) + pow(b, 2)) / 2;
    double srednee2 = (fabs(a) + fabs(b)) / 2;
    printf("srednee pow = %.2lf\nsrednee module = %.2lf\n\n\n", srednee, srednee2);
    return 0;
}