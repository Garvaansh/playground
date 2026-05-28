package main

import "fmt"

// public or global variable
const LoginToken string = "abc123"

func main() {
	// fmt.Println("Hello world!")

	var name string = "Ansh"
	fmt.Println(name)
	fmt.Printf("Variable is of type: %T \n", name)

	var isLoggedIn bool = true
	fmt.Println(isLoggedIn)
	fmt.Printf("Variable is of type: %T \n", isLoggedIn)

	/** To find the range of a  data type like uint8, etc
	* ! for uint8, the range is 0 to 255.
	* ! for uint16, the range is 0 to 65535.
	* ! for uint32, the range is 0 to 4294967295.
	* ! for uint64, the range is 0 to 18446744073709551615.

	* ! for int8, the range is -128 to 127.
	* ! for int16, the range is -32768 to 32767.
	* ! for int32, the range is -2147483648 to 2147483647.
	* ! for int64, the range is -9223372036854775808 to 9223372036854775807.

	* ? to find out the range of a data type, we can use 2^n - 1, where n is the number of bits used to store the data type.
	* ? For example, for uint8, n is 8, so the range is 2^8 - 1 = 255.
	* ? For int8, n is also 8, but since it can store both positive and negative numbers, the range is -2^(n-1) to 2^(n-1) - 1, which is -128 to 127.
	 */
	var val int16 = 255
	fmt.Println(val)
	fmt.Printf("Variable is of type: %T \n", val)

	var floatVar float32 = 255.23423
	fmt.Println(floatVar)
	fmt.Printf("Variable is of type: %T \n", floatVar)

	// Implicit type conversion
	var anotherVariable = 255.23423
	fmt.Println(anotherVariable)
	fmt.Printf("Variable is of type: %T \n", anotherVariable)

	/** no var keyword style, walrus operator
	*? this is allowed in go only for methods, not outside methods,
	*? example: if i write the same variable outside this main func, it will not allow me.
	 */
	numberOfUsers := 100
	fmt.Println(numberOfUsers)
	fmt.Printf("Variable is of type: %T \n", numberOfUsers)

	fmt.Println(LoginToken)
}
