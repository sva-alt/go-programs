package main

import "fmt"

func main() {

    /* Tipos de dato especificados por el usuario*/
    const a int32 = 12          //32-bit integer
    const b float32 = 24.5      //32-bit float
    var c complex128 = 1 + 4i   //128-bit complex number
    var d uint16 = 14           //16-bit unsigned integer

    /* Tipos de Dato por defecto */
    n := 40             // int
    pi := 3.14          // float64
    x, y := true, false // bool 
    z := "Hola, Go"

    fmt.Printf("Tipos de dato especificados:\n%T %T %T %T\n", a, b, c, d)
    fmt.Printf("Tipos de dato por defecto: \n")
    fmt.Printf("n = %T:%d, pi = %T:%f, x = %T:%t, y= %T:%t, z = %T:%s \n",
    n, n, pi, pi, x, x, y, y, z, z)

}





