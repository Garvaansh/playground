package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {

	randNum := rand.New(rand.NewSource(time.Now().Unix()))
	diceNum := randNum.Intn(6) + 1
	// fmt.Println("Dice number:", diceNum)

	println("the dice number (1-6):")

	switch diceNum {
	case 1:
		fmt.Println("You guessed 1")
	case 2:
		fmt.Println("You guessed 2")
	case 3:
		fmt.Println("You guessed 3")
		fallthrough
	case 4:
		fmt.Println("You guessed 4")
		fallthrough
	case 5:
		fmt.Println("You guessed 5")
	case 6:
		fmt.Println("You guessed 6")
	default:
		fmt.Println("Invalid guess")
	}

}
