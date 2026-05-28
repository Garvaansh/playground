package main

import (
	"fmt"
	"net/url"
)

const myurl string = "https://notansh.is-a.dev:3000/home?projects=chanakyanetra"

func main() {
	// parsing
	result, err := url.Parse(myurl)
	checkNilerr(err)

	fmt.Println(result.Scheme)
	fmt.Println(result.Host)
	fmt.Println(result.Path)
	fmt.Println(result.Port())
	fmt.Println(result.RawQuery)

	// Build the URL
	parts := &url.URL{
		Scheme: "https",
		Host:   "notansh.is-a.dev",
		Path:   "",
	}

	anotherurl := parts.String()
	fmt.Println(anotherurl)
}

func checkNilerr(err error) {
	if err != nil {
		panic(err)
	}
}
