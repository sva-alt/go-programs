package main


import (
    "fmt"
)

func main() {

    c := make(chan int) // Crea un canal para pasar enteros

    for i := 0; i < 5; i++ {
        go cookingGopher(i,c) // Inicia goroutine
    }

    for i := 0; i < 5; i++ {
        gopherID := <-c // recibe valores del canal
        fmt.Println("gopher", gopherID, "acabo su plato")
    }   // todas la goroutines acaban en este punto
}

/* notese que el canal es un argumento */
func cookingGopher(id int, c chan int) {
    fmt.Println("gopher", id, "empezo a cocinar")
    c <- id // manda el valor a main
}

