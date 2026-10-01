#include <stdio.h>
#include <float.h>

int main(){
    
    double a = 1.0;
    printf("The maximum value of double is: %e\n", a);
    
    do{
        a /= 2.0;
        //printf("Current value of a: %e\n", a);
    } while (1 != 1+a);
    printf("The smallest value of a such that a != 1 + a is: %e\n", a);
    printf("Real machine zero is %e\n", DBL_EPSILON);
    
    float a1 = 1.0f;

    do{
        a1 /= 2.0f;
        //printf("Current value of a: %e\n", a1);
    } while (1.f != 1.f+a1);
    printf("The smallest value of a such that a != 1 + a is: %e\n", a1);
    printf("Real machine zero is %e\n", FLT_EPSILON);

    long double a2 = 1.0L;

    do{
        a2 /= 2.0L;
        //printf("Current value of a: %e\n", a);
    } while (1 != 1+a2);
    printf("The smallest value of a such that a != 1 + a is: %Le\n", a2);
    printf("Real machine zero is %Le\n", LDBL_EPSILON);

}