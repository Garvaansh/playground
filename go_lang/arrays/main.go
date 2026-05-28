package main

import "fmt"

func main() {
	var list [4]string

	list[0] = "Hello"
	list[1] = "World"
	list[2] = "Go"

	fmt.Println(list)
	fmt.Println(len(list))

	var secList = [4]string{"hehe"}
	fmt.Println(secList)
}
