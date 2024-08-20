#include <stdio.h>

int main(){

    char *nombres_mascotas[5] = {"Tommy", "Zeus", "Coco", "Toby"};

    for(int i = 0; i < 4; i++){
        printf("%d %s \n",i , nombres_mascotas[i]);
    }
    return 0;
}

