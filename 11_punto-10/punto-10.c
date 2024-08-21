#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define LENGTH 500
#define MIN_RANGE 0
#define MAX_RANGE 1000

int out[LENGTH];

void *avgArr(void *count){

  int *len = (int *) count;
  int sum = 0;
  int* result = malloc(sizeof(int));
  int i;
  for (i = 0; i < *len; i++){
    sum += out[i];
  }
  *result = sum/(*len + 1);
  // printf("El valor promedio es: %d\n", result);

  return (void*) result;
}

void *minArr(void *count){
  int *len = (int *) count;
  int *min_num = malloc(sizeof(int));

  int i;
  for (i = 0; i < *len; i++){
    if (i == 0 || out[i] < *min_num){
      *min_num = out[i];
    }
  }
  //printf("El valor mínimo es: %d\n", *min_num);
  return (void*) min_num;
}

void *maxArr(void *count){
  int *len = (int *) count;
  int *max_num = malloc(sizeof(int));
  
  int i;
  for (i = 0; i < *len; i++){
    if (i == 0 || out[i] > *max_num){
      *max_num = out[i];
    }
  }
  // printf("El valor máximo es: %d\n", max);

  return (void*) max_num;
}

int main(int argc, char *argv[])
{
  
  
  /*
  printf("Digita los números a evaluar, separalos con espacio:\n");
  scanf("%[^\n]s", str);
  */
  int count = LENGTH;
  int fd = open("/dev/urandom", O_RDONLY);
  printf("[ ");
  for (int i = 0; i < count; i++) {
    unsigned int rd_num;
    read(fd, &rd_num, sizeof(rd_num));
    out[i] = rd_num % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE; //chagne first two numbers, the max and min, to change the range of the random numbers
    printf("%d ", out[i]);
  }

  close(fd);

  printf("]\n");
            

  pthread_t t1, t2, t3;
  int *res1, *res2, *res3;
  
  pthread_create(&t1, NULL, avgArr, (void *)&count);
  pthread_create(&t2, NULL, minArr, (void *)&count);
  pthread_create(&t3, NULL, maxArr, (void *)&count);

  pthread_join(t1, (void**) &res1);
  pthread_join(t2, (void**) &res2);
  pthread_join(t3, (void**) &res3);


  printf("El valor promedio es: %d\n", *res1);
  printf("El valor mínimo es: %d\n", *res2);
  printf("El valor máximo es: %d\n", *res3);

  free(res1);
  free(res2);
  free(res3);

  return 0;
}


