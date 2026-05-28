package main

import (
	"fmt"
)

func main() {
	// goroutine is created by using the keyword "go" before a function call
	// just typing "go" before a function call will create a new goroutine that runs concurrently with the main goroutine
	// but it'll never wait for the goroutine to finish before exiting the main function,
	//so we need to use a synchronization mechanism to wait for the goroutine to finish before exiting the main function

	go greeter("Hello")
	greeter("World")

}

func greeter(s string) {
	for i := 0; i < 5; i++ {
		// methods to actually wait for the goroutine to finish before exiting the main function include using channels, wait groups, or other synchronization primitives
		// ! 1. Using time.Sleep()
		// time.Sleep(3 * time.Millisecond)
		// ! 2. using  package like sync -> gives `mutex` and `wait group` to synchronize goroutines

		fmt.Println(s, i)
	}
}
