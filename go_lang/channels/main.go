package main

import (
	"fmt"
	"sync"
)

func main() {
	myCh := make(chan int, 2) // buffered channel with capacity of 2

	wg := &sync.WaitGroup{} //! these are pointers

	// myCh <- 5 //! this is a blocking operation, it will wait until some one receives the value from the channel
	// returns  a deadlock error because there is no one to receive the value from the channel
	// fmt.Println(<-myCh)

	wg.Add(2)

	// Receive only <-chan
	go func(ch <-chan int, wg *sync.WaitGroup) {
		value, isChannelOpen := <-myCh
		if !isChannelOpen {
			fmt.Println("Channel is closed, no more values to receive.")
		}
		fmt.Println(value)
		// fmt.Println(<-myCh)
		wg.Done()
	}(myCh, wg)

	// Send only chan<-
	go func(ch chan<- int, wg *sync.WaitGroup) {
		myCh <- 0
		close(myCh) // close the channel after sending all the values, this will signal the receiver that there are no more values to receive

		// myCh <- 6
		wg.Done()
	}(myCh, wg)

	wg.Wait()

}
