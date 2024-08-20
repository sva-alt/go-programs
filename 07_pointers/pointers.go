package main

import "fmt"

func main() {
    var direccion *int      // declaras puntero int
    numero := 42            // int
    direccion = &numero    // direccion guarda al numero
    valor := *direccion     // dereferencial al valor

    fmt.Printf("direccion: %v\n", direccion)    // direccion
    fmt.Printf("valor: %v\n", valor)            // valor: 42
}
