package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/gorilla/mux"
)

func main() {
	fmt.Println("Hellow")
	greeter()

	r := mux.NewRouter()
	r.HandleFunc("/", serveHome).Methods("GET")

	log.Fatal(http.ListenAndServe(":8000", r))

}

func greeter() {
	fmt.Println("hehehe")
}

func serveHome(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1> Welcome to home page </h1>"))
}
