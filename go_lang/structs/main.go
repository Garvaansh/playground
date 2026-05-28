package main

import "fmt"

func main() {
	// No inheritance in Go, no super or parent classes

	ansh := User{
		"Ansh", "ansh@go.com", true, 21}
	fmt.Println(ansh)
	fmt.Printf("Details: %+v\n", ansh)
	fmt.Printf("Details: name is %v, age is %v\n", ansh.Name, ansh.Age)

}

type User struct {
	Name   string
	Email  string
	Status bool
	Age    int
}
