#include <stdio.h>
#include <math.h>
   
int main(){
    double a, b, time1, time2, distance;
    printf("third programm\nEnter the speed of the boat and the speed of the river flow  ");
    scanf("%lf %lf", &a, &b);
    printf("enter the time 1 and time 2(time 1 < time 2)  ");
    scanf("%lf %lf", &time1, &time2);
    distance = ((a + b) * time1) + ((a - b) * time2);
    printf("distance = %.2lf\n\n\n", distance);
    return 0;
}