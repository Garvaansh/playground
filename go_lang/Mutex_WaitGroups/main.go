package main

import (
	"fmt"
	"sync"
)

func main() {

	wg := &sync.WaitGroup{} //! these are pointers
	mut := &sync.Mutex{}    //! these are pointers

	var score = []int{0}

	wg.Add(3)

	// lambda functions

	// All these are  causing race condition
	// try running it as go run --race . returns statuscode 66
	// for this we need mutex.
	go func(wg *sync.WaitGroup, m *sync.Mutex) {
		fmt.Println("One R")

		mut.Lock()
		score = append(score, 1)
		mut.Unlock()

		wg.Done()
	}(wg, mut)

	// wg.Add(3)
	go func(wg *sync.WaitGroup, m *sync.Mutex) {
		fmt.Println("Two R")

		mut.Lock()
		score = append(score, 2)
		mut.Unlock()

		wg.Done()
	}(wg, mut)

	go func(wg *sync.WaitGroup, m *sync.Mutex) {
		fmt.Println("Three R")

		mut.Lock()
		score = append(score, 3)
		mut.Unlock()

		wg.Done()
	}(wg, mut)

	wg.Wait()

	fmt.Println(score)

}
