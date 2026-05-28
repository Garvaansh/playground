package main

import (
	"fmt"
	"net/http"
	"sync"
)

// Variable global to package  for sync in wait groups
var wg sync.WaitGroup //! these are pointers
var mut sync.Mutex    //! these are pointers

// i am not using them as pointers rn..

var signals = []string{
	"test",
}

func main() {

	websiteList := []string{
		"https://notansh.is-a.dev",
		"https://www.google.com",
		"https://www.facebook.com",
		"https://www.github.com",
	}

	for _, web := range websiteList {

		wg.Add(1)

		go func(endpoint string) {
			defer wg.Done()

			statusCode, err := getStatusCode(endpoint)
			if err != nil {
				fmt.Printf(
					"Error fetching %s: %v\n",
					endpoint,
					err,
				)
				return
			}

			// this looks fine, but
			// Multiple goroutines are running at the same time,
			// and all of them are trying to modify the same slice.
			//
			// The problem is:
			// append() is not a simple operation internally.
			//
			// While appending, Go may:
			// - change the slice length
			// - grow the capacity
			// - allocate a new array
			// - copy old values into new memory
			//
			// If two goroutines try to append at the same time,
			// they may both try to modify the slice together.
			//
			// That can lead to:
			// - missing values
			// - overwritten values
			// - corrupted slice state
			// - random unpredictable behavior
			//
			// A mutex fixes this by allowing only one goroutine
			// to access this critical section at a time.

			// Lock the shared slice before modifying it.
			// This ensures only one goroutine can append at a time.
			mut.Lock()

			signals = append(signals, endpoint)

			mut.Unlock()

			fmt.Printf(
				"Status code for %s: %d\n",
				endpoint,
				statusCode,
			)

		}(web)
	}

	wg.Wait()

	fmt.Println(signals)
}

func getStatusCode(endpoint string) (int, error) {
	res, err := http.Get(endpoint)
	if err != nil {
		return 0, err
	}

	return res.StatusCode, nil
}
