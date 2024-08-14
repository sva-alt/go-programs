#include <stdio.h>
#include <stdlib.h> // trae NULL pointers
#include <pthread.h> // libreria para manejar threads en c
#include <unistd.h>


void *cookingThread(void* arg){
    int *id = (int*)arg;
    printf("Thread %d empezo a cocinar\n", *id);
    free(arg);
}


int main(){
    pthread_t tid[5];
    for(int i = 0; i<5; i++){
        int* a = malloc(sizeof(int));
        *a = i;
        pthread_create(&tid[i], NULL, cookingThread, a);
    }

    for(int i = 0; i<5; i++){
        pthread_join(tid[i], NULL);
        printf("Thread %d acabo su plato \n", i);
    }

    return 0;
}


