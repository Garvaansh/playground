package main

import "fmt"

func main() {

	days := []string{"Sunday", "Monday", "Tueday", "Wednesday", "Thursday", "Friday", "Saturday"}

	fmt.Println(days)

	/**
	* ! Basic for loop from 0 -> n
	 */
	// for d := 0; d < len(days); d++ {
	// 	fmt.Println("Today is", days[d])
	// }

	/**
	* ! for loop over a range of an array/slice
	* ? it still returns an index, unlike auto& : nums in cpp which gives element/data itself
	 */
	// for i := range days {
	// 	fmt.Println(days[i])
	// }

	/**
	* * this with _ or idx,  day,  we can access data as well
	 */
	// for _, day := range days {
	// 	fmt.Printf("Day: %s\n", day)
	// }

	rougueVal := 1
	for rougueVal < 5 + 1 {
		fmt.Println("Rougue value is", rougueVal)
		rougueVal++
	}

}
