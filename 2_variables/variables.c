#include <stdio.h>
#include <stdbool.h>
#define d 10 //definiendo variable constante

// definiendo variable de tipado estatico
int a = 1;

// definiendo multiples variables
int b = 10, c = 0;

bool e = true;

float f = 1.55;

char g[10] = "hola mundo";

int main(){

    a = a*10;

    printf("%i \n", a+b+c+d);
    printf("%i \n", d);
    printf("%d \n", e);
    printf("%f \n", f);
    printf("%s \n", g);
    

    return 0;
}
      







