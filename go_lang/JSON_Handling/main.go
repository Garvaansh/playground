package main

import (
	"encoding/json"
	"fmt"
)

type course struct {
	Name     string `json:"CourseName"`
	Price    int
	Platform string   `json:"website"`
	Password string   `json:"-"`              // completely ignores this field during encoding and decoding
	Tags     []string `json:"tags,omitempty"` // if the field is empty, it will be omitted from the JSON output
}

func main() {
	//Encoding of a JSON object
	// EncodeJson()

	// Decoding of a JSON object
	DecodeJson()
}

func EncodeJson() {
	coursesObj := []course{
		{"ReactJS Bootcamp", 299, "Udemy", "abc123", []string{"web-dev", "js"}},
		{"Angular Bootcamp", 199, "Udemy", "def456", []string{"web-dev", "js"}},
		{"Go Bootcamp", 399, "Udemy", "ghi789", nil},
	}

	// Package this data as JSON data

	// myJson, err := json.Marshal(coursesObj)
	myJson, err := json.MarshalIndent(coursesObj, "", "\t")
	checkNilerr(err)

	fmt.Printf("%s\n", myJson)
}

func DecodeJson() {
	jsonData := []byte(`
	{
                "CourseName": "ReactJS Bootcamp",
                "Price": 299,
                "website": "Udemy",
                "tags": [
                        "web-dev",
                        "js"
                ]
        }
	`)

	var courseObj course

	checkValid := json.Valid(jsonData)

	if checkValid {
		fmt.Println("JSON data is valid")
		err := json.Unmarshal(jsonData, &courseObj)
		checkNilerr(err)
		fmt.Printf("%#v\n", courseObj)
	} else {
		fmt.Println("JSON data is not valid")
	}

	// Use case: if we want to just get the value of a particular key from the JSON data without unmarshalling it into a struct
	// key will always be string, but the values can be of any data type, so use `interface{}` to handle all data types
	var data map[string]interface{}
	json.Unmarshal(jsonData, &data)
	fmt.Printf("%#v\n", data)

	for key, value := range data {
		fmt.Printf("Key: %v, Value: %v, Type of value: %T\n", key, value, value)
	}
}

func checkNilerr(err error) {
	if err != nil {
		panic(err)
	}
}
