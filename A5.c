#include <stdio.h>

int main(){
    double r, l, s;
    printf("fiveth programm\nEnter l  ");
    scanf("%lf", &l);
    r = l / (2 * 3.14);
    s = 3.14 * r * r;
    printf("Square = %.2lf\n\n\n", s);
    return 0;
}