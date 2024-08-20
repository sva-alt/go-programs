package main

import "fmt"

/* Definir el tipo de dato stack usando struct */
type stack struct {
    index int
    data [5]int
}

/* Definir los metodos push y pop */
func (s *stack) push(k int) {
    s.data[s.index] = k
    s.index++
}

func (s *stack) pop() int {
    s.index--
    return s.data[s.index]
}

func main() {
    /* Crea un puntero a una nueva stack y haz push a dos valores */
    s := new(stack)
    s.push(23)
    s.push(14)
    fmt.Printf("stack: %v\n", *s) //stack: {2 [23 14 0 0 0]}
}


