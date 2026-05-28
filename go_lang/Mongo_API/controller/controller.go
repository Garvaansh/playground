package controller

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"os"
	"strconv"
	"time"

	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"

	"github.com/Garvaansh/mongoAPI/model"
	"github.com/gorilla/mux"
)

// ! MOST IMPORTANT
var collection *mongo.Collection

var appStartTime = time.Now()

// connect with mongodb
func ConnectDB() {

	// Get the environment variables
	var dbURL = os.Getenv("GO_dburl")
	var dbName = os.Getenv("GO_dbname")
	var colName = os.Getenv("GO_colName")

	fmt.Println("Connecting to MongoDB...")

	// client option
	clientOption := options.Client().ApplyURI(dbURL)

	//  connect to mongodb
	client, err := mongo.Connect(context.TODO(), clientOption)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("MongoDB connection success")

	collection = client.Database(dbName).Collection(colName)

	// Collection instance
	fmt.Println("Collection instance ready")
}

// MongoDB Helpers - file
// insert one record

func insertOneMovie(movie model.Netflix) {
	inserted, err := collection.InsertOne(context.Background(), movie)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Inserted a single record ", inserted.InsertedID)
}

// Update one record
func updateOneMovie(movieId string) {
	id, _ := primitive.ObjectIDFromHex(movieId)

	/** Difference between BSON.D and BSON.M
	*!  M is shorter and easier to write,
	*! but D preserves the order of the fields, which can be important in some cases.
	 */

	filter := bson.M{"_id": id}
	update := bson.M{"$set": bson.M{"watched": true}}

	result, err := collection.UpdateOne(context.Background(), filter, update)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Modified count: ", result.ModifiedCount)
}

func deleteONeMovie(movieId string) {
	id, _ := primitive.ObjectIDFromHex(movieId)

	filter := bson.M{"_id": id}

	result, err := collection.DeleteOne(context.Background(), filter)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Deleted count: ", result.DeletedCount)
}

func deleteAllMovies() int64 {
	filter := bson.D{{}} // Empty filter to match all documents

	result, err := collection.DeleteMany(context.Background(), filter)
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("Deleted count: ", result.DeletedCount)
	return result.DeletedCount
}

// get all movies from db
func getAllMovies() []primitive.M {
	cursor, err := collection.Find(context.Background(), bson.D{{}})
	if err != nil {
		log.Fatal(err)
	}

	var movies []primitive.M

	for cursor.Next(context.Background()) {
		var movie bson.M
		err := cursor.Decode(&movie)
		if err != nil {
			log.Fatal(err)
		}

		movies = append(movies, movie)
	}

	defer cursor.Close(context.Background())

	return movies
}

// Controller functions
func HealthCheck(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")

	// Check MongoDB status
	dbStatus := "connected"
	dbName := os.Getenv("GO_dbname")

	err := collection.Database().RunCommand(
		context.Background(),
		bson.M{"ping": 1},
	).Err()

	if err != nil {
		dbStatus = "disconnected"
	}

	// Uptime calculation
	UnFormat_uptime := time.Since(appStartTime)
	hours := int(UnFormat_uptime.Hours())
	minutes := int(UnFormat_uptime.Minutes()) % 60
	seconds := int(UnFormat_uptime.Seconds()) % 60

	uptime := fmt.Sprintf(
		"%02d:%02d:%02d",
		hours,
		minutes,
		seconds,
	)

	// Environment
	environment := os.Getenv("GO_ENV")
	if environment == "" {
		environment = "development"
	}

	// Response object
	response := map[string]interface{}{
		"status":      "healthy",
		"timestamp":   time.Now().Format("2006-01-02 15:04:05"),
		"uptime":      uptime,
		"version":     "1.0.0",
		"environment": environment,

		"database": map[string]interface{}{
			"name":   dbName,
			"status": dbStatus,
		},

		"services": map[string]interface{}{
			"mongodb": dbStatus,
		},
	}

	json.NewEncoder(w).Encode(response)
}

func GetAllMovies(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")

	allMovies := getAllMovies()

	json.NewEncoder(w).Encode(allMovies)
}

func CreateMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Allow-Control-Allow-Methods", "POST")

	var movie model.Netflix
	_ = json.NewDecoder(r.Body).Decode(&movie)
	insertOneMovie(movie)

	msg := "Movie created successfully" + movie.Movie
	json.NewEncoder(w).Encode(msg)
}

func MarkAsWatched(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Allow-Control-Allow-Methods", "PUT")

	params := mux.Vars(r)
	updateOneMovie(params["id"])

	msg := "Movie marked as watched successfully"
	json.NewEncoder(w).Encode(msg)
}

func DeleteAMovie(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Allow-Control-Allow-Methods", "DELETE")

	params := mux.Vars(r)
	deleteONeMovie(params["id"])

	msg := "Movie deleted successfully"
	json.NewEncoder(w).Encode(msg)
}

func DeleteAllMovies(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/x-www-form-urlencoded")
	w.Header().Set("Allow-Control-Allow-Methods", "DELETE")

	count := deleteAllMovies()

	msg := "Movies deleted successfully, Count :" + strconv.Itoa(int(count))
	json.NewEncoder(w).Encode(msg)

}
