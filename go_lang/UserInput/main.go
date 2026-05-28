package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	welcome := "Welcome User!"
	
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter your name: ")

	//  comma ok || Error handling
	// here we are ignoring the error, but in real world applications, we should handle the error properly.
	// this can be done by using the if statement to check if the error is nil or not.
	// Usage:  input, err := reader.ReadString('\n')
	input, _ := reader.ReadString('\n')
	fmt.Println(welcome, input)
	fmt.Printf("Type of input is: %T", input)

}
