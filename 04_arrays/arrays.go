package main

import "fmt"

func main() {
    /* Define un arreglo de tamaño 4 de nombre de mascotas*/

    var NombresMascotas = [4]string{"Tommy", "Zeus", "Coco", "Toby"}
    // podemos usar ... en vez de 4.


    /* Recorre todo el arreglo */
    for index, option := range NombresMascotas {
        // range itera sobre los items de un arreglo, 'slice' o 'map' 
        fmt.Println(index, option)
    }
}








