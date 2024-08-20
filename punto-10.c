#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <ctype.h>

int out[500];

void *prom(void *count){

  int *len = (int *) count;
  int sum = 0;
  int* result = malloc(sizeof(int));
  int i;
  for (i = 0; i < *len + 1; i++){
    sum += out[i];
  }
  *result = sum/(*len + 1);
  // printf("El valor promedio es: %d\n", result);

  return (void*) result;
}

void *min(void *count){
  int *len = (int *) count;
  int *min = malloc(sizeof(int));
  *min = out[0];

  int i;
  for (i = 1; i < *len + 1; i++){
    if (out[i] < *min){
      *min = out[i];
    }
  }
  //printf("El valor mínimo es: %d\n", min);
  return (void*) min;
}

void *max(void *count){
  int *len = (int *) count;
  int *max = malloc(sizeof(int));
  *max = out[0];
  
  int i;
  for (i = 1; i < *len + 1; i++){
    if (out[i] > *max){
      *max = out[i];
    }
  }
  // printf("El valor máximo es: %d\n", max);

  return (void*) max;
}

int main(int argc, char *argv[])
{
  
  
  char str[500];

  printf("Digita los números a evaluar, separalos con espacio:\n");
  scanf("%[^\n]s", str);
  
  int i = 0; /* Se encarga del char a evaluar */
  int count = 0; /* Cuenta en que posición del arreglo out debe quedar el número, len()-1 de out */
  int prev = 0; /*Lleva la cuenta de los números que se han evaluado */
  while (str[i] != '\0'){ /* Verifica que no estemos al final de la cadena */
    if (isdigit(str[i]) > 0){ /* Verifica que el char sea un número */
      int digit = str[i] - '0'; /* Convierte el char a int */
      prev = prev * 10 + digit; /* Concatena los números */
    }
    else if (isspace(str[i]) > 0){
      out[count] = prev; /* Añade el número al arreglo */
      prev = 0; /* Reinicia el contador */
      count++; /* Alista la siguiente posición del arreglo */
    } 
    else {
      printf("Error: %c\n", str[i]);
    }
    i++;
  }
  out[count]=prev; /* Agrega el último número */


  pthread_t t1, t2, t3;
  int *res1, *res2, *res3;
  
  pthread_create(&t1, NULL, prom, (void *)&count);
  pthread_create(&t2, NULL, min, (void *)&count);
  pthread_create(&t3, NULL, max, (void *)&count);

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


