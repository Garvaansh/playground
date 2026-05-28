package main

import (
	"fmt"
	"log"
	"net/http"

	"github.com/Garvaansh/mongoAPI/controller"
	"github.com/Garvaansh/mongoAPI/router"
	"github.com/joho/godotenv"
)

func loadEnv() {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading .env file")
	}
}

func main() {
	fmt.Println("Startiing the application...")

	loadEnv()

	controller.ConnectDB()

	r := router.Router()

	fmt.Println("Server is running on port 8000")
	log.Fatal(http.ListenAndServe(":8000", r))
}
