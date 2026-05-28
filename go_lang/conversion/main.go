package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	welcome := "Welcome User to the Pizza Store!  \n Kindly rate us between 1 to 5. \n"
	fmt.Println(welcome)

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Input your rating please: ")

	//  comma ok || Error handling
	// here we are ignoring the error, but in real world applications, we should handle the error properly.
	// this can be done by using the if statement to check if the error is nil or not.
	// Usage:  input, err := reader.ReadString('\n')
	ThankMessage := "Thank you for your feedback! We will try to improve our services."

	input, _ := reader.ReadString('\n')

	fmt.Println(ThankMessage, input)
	// fmt.Printf("Type of input is: %T", input)

	// Typecase the number string to int
	numRating, err := strconv.ParseInt(strings.TrimSpace(input), 10, 64)
	if err != nil {
		fmt.Println("Error in typecasting the input to int: ", err)
	} else {
		fmt.Printf("Type of numRating is: %T", numRating)
	}

}
