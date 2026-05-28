package main

import (
	"io"
	"net/http"
)

const url = "https://notansh.is-a.dev"

func main() {

	response, err := http.Get(url)

	if err != nil {
		panic(err)
	}
	defer response.Body.Close()

	println("Response: %T", response)
	println("Status code: ", response.StatusCode)

	databytes, err := io.ReadAll(response.Body)
	checkNilerr(err)

	println(string(databytes))
}

func checkNilerr(err error) {
	if err != nil {
		panic(err)
	}
}
