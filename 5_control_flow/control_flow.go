package main

import "fmt"

/* Define una función que encuentre la media aritmetica de los numeros reales en el slice */

func media(x []float64) (m float64) {
    total := 0.0
    if len(x) == 0 {
        m = 0
    } else {
        for _,v := range x {
            total += v
        }
        m = total / float64(len(x))
    }
    return
}

func main() {
    x := []float64{2.15, 3.14, 42.0, 29.5}
    fmt.Println(media(x))       //19.197499999999998
}
