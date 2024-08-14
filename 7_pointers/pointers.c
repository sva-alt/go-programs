#include <stdio.h>

int main() {
    int *direccion;
    int numero = 42;
    direccion = &numero;
    int valor = *direccion;

    printf("direccion: %p\n", direccion);
    printf("valor: %d\n", valor);

    return 0;
}
