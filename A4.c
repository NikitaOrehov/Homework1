#include <stdio.h>

int main(){
    double speed1, speed2, time, distance1, distance2;
    printf("fourth programm\nEnter the speed of the first and second car  ");
    scanf("%lf %lf", &speed1, &speed2);
    printf("Enter time and S  ");
    scanf("%lf %lf", &time, &distance1);
    distance2 = distance1 + ((speed1 + speed2) * time);
    printf("Distance = %.2lf\n\n\n", distance2);
    return 0;
}