package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	content := "This is a sample content"

	file, err := os.Create("Sample.txt")
	if err != nil {
		panic(err)
	} else {
		defer file.Close()
	}

	length, err := io.WriteString(file, content)
	if err != nil {
		panic(err)
	} else {
		fmt.Println(length)
	}

	readFile("Sample.txt")
}

func readFile(filename string) {
	// databytes, err, is generally how data/file is being read
	databytes, err := os.ReadFile(filename)
	if err != nil {
		panic(err)
	}

	// prints the content of the file as bytes 
	fmt.Println(databytes)
	fmt.Println(string(databytes))
}
