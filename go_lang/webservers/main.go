package main

import (
	"fmt"
	"io"
	"net/http"
	"net/url"
	"strings"
)

const _url = "http://localhost:3000"

func main() {
	PerformGetRequest()
	PerformPostRequest()
	PerformPostFormRequest()
}

func PerformGetRequest() {
	const myurl string = _url + "/get"

	res, err := http.Get(myurl)
	checkNilerr(err)

	defer res.Body.Close()

	fmt.Println("Status code: ", res.StatusCode)

	//  Better option, Strings.Builder method is more efficient than byte slice to string conversion
	var responseString strings.Builder

	content, _ := io.ReadAll(res.Body)
	byteCount, _ := responseString.Write(content)
	fmt.Println("Byte count: ", byteCount)
	fmt.Println("Response string: ", responseString.String())

	// Uses the byte slice to string conversion
	// fmt.Println(string(content))

}

func PerformPostRequest() {
	const myurl string = _url + "/post"

	// fake JSON payload
	requestBody := strings.NewReader(`
		{
			"name": "Ansh",
			"age": 22,
			"email": "anshhehe@gmail.com"}
	`)

	response, err := http.Post(myurl, "application/json", requestBody)
	checkNilerr(err)

	defer response.Body.Close()
	fmt.Println("Status code: ", response.StatusCode)

	var responseBody strings.Builder

	content, _ := io.ReadAll(response.Body)
	byteCount, _ := responseBody.Write(content)
	fmt.Println("Byte count: ", byteCount)
	fmt.Println("Response string: ", responseBody.String())
}

func PerformPostFormRequest() {

	const myurl string = _url + "/postform"
	//  formdata

	data := url.Values{}
	data.Add("name", "Ansh")
	data.Add("Age", "21")
	data.Add("email", "ansh@gmail.com")

	res, err := http.PostForm(myurl, data)
	checkNilerr(err)
	defer res.Body.Close()

	fmt.Println("Status code: ", res.StatusCode)
	var responseBody strings.Builder

	content, _ := io.ReadAll(res.Body)
	byteCount, _ := responseBody.Write(content)
	fmt.Println("Byte count: ", byteCount)
	fmt.Println("Response string: ", responseBody.String())
}

func checkNilerr(err error) {
	if err != nil {
		panic(err)
	}
}
