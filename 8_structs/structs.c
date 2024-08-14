#include <stdio.h>

/* Definir el tipo de dato stack usando struct */
typedef struct stack{
    int index;
    int data[5];
} stack;


/* Definir los metodos push y pull */
void push(stack *s, int k) {
    s->data[s->index] = k;
    s->index++;
}

int pull(stack *s) {
    s->index--;
    return s->data[s->index];
}

int main() {
    stack s; 
    s.index = 0;
    for (int i = 0; i < 5; i++){
        s.data[i] = 0;
    }
    stack *sptr = &s ;


    push(sptr, 23);
    push(sptr, 14);
    printf("stack: { %d ", s.index);
    printf("{ ");
    for (int i = 0; i < 5; i++){
        printf("%d ", s.data[i]);
    }
    printf("}}\n");
    return 0;
}






