package main

import "fmt"

func main() {
	languages := make(map[string]string)

	languages["go"] = "Go is a statically typed, compiled programming language designed at Google."
	languages["python"] = "Python is an interpreted, high-level and general-purpose programming language."
	languages["java"] = "Java is a class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible."

	fmt.Println(languages)
	fmt.Println(languages["go"])

	delete(languages, "java")
	fmt.Println(languages)

	for key, value := range languages {
		fmt.Printf("Key: %v, Value: %v\n", key, value)
	}
}
