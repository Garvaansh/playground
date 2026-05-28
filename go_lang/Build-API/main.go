package main

import (
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"strconv"
	"time"

	"github.com/gorilla/mux"
)

// Model for course - file
type Course struct {
	CourseId   string  `json:"courseid"`
	Name       string  `json:"coursename"`
	Price      int     `json:"courseprice"`
	AuthorInfo *Author `josn:"author"`
}

type Author struct {
	Fullname string `json:"fullname"`
	Website  string `json:"website"`
}

// Mock DB
var courses []Course

// middleware, helper functions - file
func (c *Course) IsEmpty() bool {
	return c.Name == ""
}

func main() {
	fmt.Println("API - Building API in Golang")

	r := mux.NewRouter()

	// Seeding
	courses = append(courses, Course{CourseId: "2", Name: "ReactJS Bootcamp", Price: 299, AuthorInfo: &Author{Fullname: "John Doe", Website: "john.com"}})
	courses = append(courses, Course{CourseId: "4", Name: "Angular Bootcamp", Price: 400, AuthorInfo: &Author{Fullname: "Ansh Doe", Website: "ansh.com"}})
	courses = append(courses, Course{CourseId: "6", Name: "MERN Bootcamp", Price: 696, AuthorInfo: &Author{Fullname: "Hehe Doe", Website: "hehe.com"}})
	courses = append(courses, Course{CourseId: "1", Name: "Go Bootcamp", Price: 677, AuthorInfo: &Author{Fullname: "Meow Doe", Website: "meow.com"}})

	r.HandleFunc("/", serveHome).Methods("GET")
	r.HandleFunc("/courses", getAllCourses).Methods("GET")
	r.HandleFunc("/courses/{id}", getOneCourse).Methods("GET")
	r.HandleFunc("/new-course", createOneCourse).Methods("POST")
	r.HandleFunc("/course/{id}", updateOneCouse).Methods("PUT")
	r.HandleFunc("/course/{id}", deleteOneCourse).Methods("DELETE")

	// listen to port
	log.Fatal(http.ListenAndServe(":8000", r))

}

// controllers  - file
// Serve Home route

func serveHome(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("<h1>Welcome to API by Golang</h1>"))
}

func getAllCourses(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Get all courses")
	w.Header().Set("Content-Type", "application/json")

	// Seeding
	json.NewEncoder(w).Encode(courses)
}

func getOneCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Get one course")
	w.Header().Set("Content-Type", "application/json")

	// grad id from request - string
	params := mux.Vars(r)

	// loop through courses, find matching id and return the response
	for _, course := range courses {
		if course.CourseId == params["id"] {
			json.NewEncoder(w).Encode(course)
			return
		}
	}

	msg := fmt.Sprintf("No course found with given id: %v", params["id"])
	json.NewEncoder(w).Encode(msg)
}

func createOneCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Create one course")
	w.Header().Set("Content-Type", "application/json")

	if r.Body == nil {
		json.NewEncoder(w).Encode("Please send some data")
	}

	// if data is sent like {}

	var course Course
	_ = json.NewDecoder(r.Body).Decode(&course)
	if course.IsEmpty() {
		json.NewEncoder(w).Encode("No data inside JSON")
		return
	}

	// Check if the given data already exists
	for _, c := range courses {
		if course.Name == c.Name {
			json.NewEncoder(w).Encode("Course already exists with given name")
			return
		}
	}

	// generate unique id, string
	// append course  into courses
	rand.New(rand.NewSource(time.Now().Unix()))
	course.CourseId = strconv.Itoa(rand.Intn(1000))
	courses = append(courses, course)
	json.NewEncoder(w).Encode(course)
}

func updateOneCouse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Update one course")
	w.Header().Set("Content-Type", "application/json")

	// 1. Grab id from request
	params := mux.Vars(r)
	var isChanged bool = false
	// 2. Loop through courses, find matching id and remove the course from the slice
	for index, course := range courses {
		if course.CourseId == params["id"] {
			courses = append(courses[:index], courses[index+1:]...)
			var course Course
			_ = json.NewDecoder(r.Body).Decode(&course)
			course.CourseId = params["id"]
			courses = append(courses, course)
			json.NewEncoder(w).Encode(course)
			isChanged = true
			return
		}
	}

	// ! send a response when id is not found
	if !isChanged {
		msg := fmt.Sprintf("No course found with given id: %v", params["id"])
		json.NewEncoder(w).Encode(msg)
	}
}

func deleteOneCourse(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Delete one course")
	w.Header().Set("Content-Type", "application/json")

	// 1. Grab id from request
	params := mux.Vars(r)
	var isDeleted bool = false

	// 2. Loop through courses, find matching id and remove the course from the slice
	for index, course := range courses {
		if course.CourseId == params["id"] {
			courses = append(courses[:index], courses[index+1:]...)
			isDeleted = true
			json.NewEncoder(w).Encode("Course is deleted successfully")
			return
		}
	}

	// ! send a response when id is not found
	if !isDeleted {
		msg := fmt.Sprintf("No course found with given id: %v", params["id"])
		json.NewEncoder(w).Encode(msg)
	}

}
