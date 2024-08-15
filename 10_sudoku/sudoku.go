package main

import (
	"fmt"
	"sync"
	"time"
)

var x, y, z int

var sudoku = [9][9]int{
	{7, 9, 2, 1, 5, 4, 3, 8, 6},
	{6, 4, 3, 8, 2, 7, 1, 5, 9},
	{8, 5, 1, 3, 9, 6, 7, 2, 4},
	{2, 6, 5, 9, 7, 3, 8, 4, 1},
	{4, 8, 9, 5, 6, 1, 2, 7, 3},
	{3, 1, 7, 4, 8, 2, 9, 6, 5},
	{1, 3, 6, 7, 4, 8, 5, 9, 2},
	{9, 7, 4, 2, 1, 5, 6, 3, 8},
	{5, 2, 8, 6, 3, 9, 4, 1, 7},
}

func checkRows() {
	for i := 0; i < 9; i++ {
		sum := 0
		for j := 0; j < 9; j++ {
			sum += sudoku[i][j]
		}
		if sum != 45 {
			x = 1
			break
		}
	}
}

func checkColumns() {
	for i := 0; i < 9; i++ {
		sum := 0
		for j := 0; j < 9; j++ {
			sum += sudoku[j][i]
		}
		if sum != 45 {
			y = 1
			break
		}
	}
}

func checkSubGrids() {
	for i := 0; i < 9; i += 3 {
		for j := 0; j < 9; j += 3 {
			sum := 0
			for k := i; k < i+3; k++ {
				for l := j; l < j+3; l++ {
					sum += sudoku[k][l]
				}
			}
			if sum != 45 {
				z = 1
				return
			}
		}
	}
}

func main() {
	var wg sync.WaitGroup
	wg.Add(3)

	start := time.Now()

	go func() {
		defer wg.Done()
		checkRows()
	}()

	go func() {
		defer wg.Done()
		checkColumns()
	}()

	go func() {
		defer wg.Done()
		checkSubGrids()
	}()

	wg.Wait()

	finished := time.Now()

	diff := finished.Sub(start)

	if x == 1 || y == 1 || z == 1 {
		fmt.Println("Invalid Solution, please try again")
	} else {
		fmt.Println("The given solution is valid.")
	}

	fmt.Println(diff.Nanoseconds())
}
