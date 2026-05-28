package router

import (
	"github.com/Garvaansh/mongoAPI/controller"
	"github.com/gorilla/mux"
)

func Router() *mux.Router {
	router := mux.NewRouter()

	router.HandleFunc("/api/health", controller.HealthCheck).Methods("GET")
	router.HandleFunc("/api/movies", controller.GetAllMovies).Methods("GET")
	router.HandleFunc("/api/new-movie", controller.CreateMovie).Methods("POST")
	router.HandleFunc("/api/movie/{id}", controller.MarkAsWatched).Methods("PUT")
	router.HandleFunc("/api/movie/{id}", controller.DeleteAMovie).Methods("DELETE")
	router.HandleFunc("/api/deleteAll", controller.DeleteAllMovies).Methods("DELETE")

	return router
}
