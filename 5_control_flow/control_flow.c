#include <stdio.h>

double media(double x[], int length) {
    double total = 0.0;
    double m;
    if (length == 0) {
       m = 0;
    } else {
       for (int i = 0; i < length; i++){
          total += x[i];
       }
       m = total / (double) length;
    }
    return m;
}


int main() {
    double x[] = {2.15, 3.14, 42.0, 29.5};
    int length = sizeof(x)/sizeof(x[0]);
    printf("%lf \n", media(x, length));           //19.127499999999998

    return 0;
}

    
