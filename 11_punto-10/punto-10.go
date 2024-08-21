package main

import (
    "fmt"
    "math/rand/v2"
)

const length int = 500
const max_range int = 1000

func main() {
    a := make(chan int)
    b := make(chan int)  
    c := make(chan int)

    var out []int

    for i := 0; i < length; i++ {
        out = append(out, rand.IntN(max_range))
    }

    printSlice(out)
    go avgIntSlice(out, a)
    go minIntSlice(out, b)
    go maxIntSlice(out, c)

    avg_ := <-a
    min_ := <-b
    max_ := <-c

    fmt.Printf("El valor promedio es: %d \n", avg_) 
    fmt.Printf("El valor mínimo es: %d \n", min_)
    fmt.Printf("El valor máximo es: %d \n", max_)

}

func printSlice(s []int) {
	fmt.Printf("%v\n", s)
}

func avgIntSlice(s []int, c chan int) {
    var sum int = 0
    for _, number := range s {
        sum += number
    }
    result := sum / len(s)

    c <- result

}

func minIntSlice(s []int, c chan int) { 
    var result int
    for index, num := range s {
        if index==0 || num < result {
            result = num
        }
    }
    c <- result
}

func maxIntSlice(s []int, c chan int) {
    var result int
    for index, num := range s {
        if index==0 || num > result {
            result = num
        }
    }
    c <- result
}




















    
