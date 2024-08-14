#include <stdio.h>
#include <stdbool.h>
#include <complex.h>

int main(){

    /* Tipos de dato especificados por el usuario*/

    const long int a = 12;           // 32-bit integer
    const float b = 24.5;           // 32-bit float 
    long complex c = 1 + 4 * I;     // 64-bit? complex number
    unsigned int d = 14;            // 16-bit unsigned integer

    int n = 40;                 // 16-bit integer 
    double pi = 3.14;           // 64-bit float
    bool x = true, y = false;   // 1-bit bool
    char z[10] = "Hola, Go";    // 8-bit for every char 

    printf("Tipos de dato especificado: \n");
    printf("n = %d, pi = %f, x = %d, y = %d, z = %s \n", n, pi, x, y, z);

    return 0;
}







    
    









