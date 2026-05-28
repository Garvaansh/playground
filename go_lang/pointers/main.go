package main

func main() {

	// pointer initialization
	var ptr *int
	println(ptr) // nil
	
	myNumber := 23
	ptr = &myNumber // assign the address of myNumber to ptr
	println(ptr) // nil
	println(*ptr) // 23

	*ptr = *ptr + 2 // update the value at the address pointed by ptr
	println(*ptr)
	println(myNumber) 
}