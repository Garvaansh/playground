package main

import "fmt"

func main() {
	// Print simply hellow world, as normal flow
	// fmt.Println("hellow")
	// defer fmt.Println("world")

	// defer executes at the end of the function, so it will print world at the end,
	// after all other statements are executed
	// Defers executes in LIFO order, meaning if there are multiple defers, the last one will execute first
	defer fmt.Println("world")
	defer fmt.Println("one")
	defer fmt.Println("two")

	fmt.Println("hellow")

	deferFunc()
}

// Prints 4 3 2 1 0, because of LNIFO order of defer
func deferFunc() {
	for i := 0; i < 5; i++ {
		defer fmt.Printf("%d\n",i)
	}
}
