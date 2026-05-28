package main

import (
	"fmt"
	"sort"
)

func main() {
	var list = []string{"Apple", "Banana", "Cherry"}
	fmt.Printf("Type: %T\n", list)
	fmt.Println(list)

	list = append(list, "Berries")
	fmt.Println(list)

	list = append(list[1:3], "")
	fmt.Println(list)

	score := make([]int, 4)

	score[0] = 90
	score[1] = 80
	score[2] = 70
	score[3] = 60
	// Cause runtime error
	// score[4] = 50
	fmt.Println(score)
	
	score = append(score, 50, 75, 67)
	fmt.Println(score)
	
	fmt.Println(sort.IntsAreSorted(score))
	sort.Ints(score)
	fmt.Println(score)


	// Remove element from slice based on index

	var courses = []string{"Go","python", "Java", "c++"}
	fmt.Println(courses)
	var idx int = 2
	courses = append(courses[:idx], courses[idx+1:]...)
	fmt.Println(courses)
}
