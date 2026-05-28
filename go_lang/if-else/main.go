package main

import (
	"fmt"
)

func main() {
	loginCount := 10

	var result string

	if loginCount < 10 {
		result = "New user"
	} else if loginCount < 50 {
		result = "Regular user"
	} else {
		result = "Power user"
	}

	fmt.Println(result)

	if num := 3; num%2 == 0 {
		fmt.Println("Even number")
	} else {
		fmt.Println("Odd number")
	}

}
