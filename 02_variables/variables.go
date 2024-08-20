package main

import "fmt"


// declarando variable de tipado estatico
var a int

// declarando variable estatica

const c int = 10

// declarando multiples variables

var (
    d bool
    e float32
    f string
)

func main(){

    a = 10

    //declarando variable de tipado estatico
    b := 10

    d, e = true, 1.55
    f = "hola mundo"

    fmt.Println(a+b+c)
    fmt.Println(c)
    fmt.Println(d)
    fmt.Println(e)
    fmt.Println(f)

}





