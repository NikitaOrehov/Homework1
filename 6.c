#include <stdio.h>
#include <math.h>

int main(){
    int x1, y1, x2, y2, x3, y3;
    double a, b, c, perimetr, square, polyperimetr;
    printf("Enter x1, y1, x2, y2, x3, y3\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    a = sqrt((pow(x2 - x1, 2) + pow(y2- y1, 2)));
    b = sqrt((pow(x3 - x2, 2) + pow(y3- y2, 2)));
    c = sqrt((pow(x3 - x1, 2) + pow(y3- y1, 2)));
    perimetr = a + b + c;
    polyperimetr = perimetr / 2;
    square = sqrt(polyperimetr * (polyperimetr - a) * (polyperimetr - b) * (polyperimetr - c));
    printf("Perimetr = %lf\nSquare = %lf", perimetr, square);
    return 0;
}