package main

import "fmt"

// main acts as the entry point of the program,
// it is a special function in Go
func main() {
	// fmt.Println("Hello world")

	result := add(2, 3)
	fmt.Println("The result is", result)

	res, msg := adder(1, 2, 3, 4, 5)
	fmt.Println("The result is", res)
	fmt.Println(msg)

	// greeter()
}

func adder(values ...int) (int, string) {
	total := 0
	for _, val := range values {
		total += val
	}

	return total, "Hehehe"
}

func add(a int, b int) int {
	return a + b
}

func greeter() {
	fmt.Println("Helloo from Golang!")
}
