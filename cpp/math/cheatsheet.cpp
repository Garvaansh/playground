#include <bits/stdc++.h>
using namespace std; 

class cheatsheet {
public:
  // Math
  void odd_even(int n);
  void count_digits(int n);
};


int main() {
  cheatsheet cs;
  cs.odd_even(10); // returns nothing.. no print statement
  cs.count_digits(12345); // returns nothing.. no print statement

    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */
// ? NOTE: These functions do not have a print statement.. 
// ? either add a print statement or change the function type to return a value.

void cheatsheet::odd_even(int n) {
  // * Approach: Use modulus operator to determine if a number is odd or even.
  // * Logic: n % 2 == 0 indicates even, else odd.
  // * Time Complexity: O(1) - constant time operation.
  // * Space Complexity: O(1) - uses a single variable.
  // * Pros: Simple and efficient.
  // ! Cons: None for integer inputs.
  /*
  if(n % 2 == 0) {
    // Even
  } else {
    // Odd
  }
  */

  // Approach 2: Bitwise AND operation
  // Logic: n & 1 is 1 if odd (true), 0 if even (false).

  // (n & 1) == 0 ?  Even : Odd ; 
  // OR
  // (n & 1) ? "Odd" : "Even";
}
void cheatsheet::count_digits(int n) {
  // * Approach 1: Iterative Division
  // * Logic: Repeatedly divide n by 10 until it becomes 0, counting each division.
  // * This works because each division removes one digit from the right.
  // * Time Complexity: O(d) or O(log10(n)) where d is number of digits (up to 10 for int).
  // * Space Complexity: O(1) - only uses a few variables.
  // * Pros: Simple, works for all integers including 0.
  // ! Cons: Slower for large numbers with many digits.
  
  /*
  int count = 0;
  int temp = n;  // Use temp to avoid modifying original n
  while(temp != 0) {
    temp = temp / 10;
    count++;
  }
  */

  // * Approach 2: Mathematical Logarithm
  // * Logic: log10(n) gives the power of 10 just below n, so floor(log10(n)) + 1 gives digit count.
  // * For example, log10(123) ≈ 2.08, floor(2.08) + 1 = 3 digits.
  // * Time Complexity: O(1) - constant time math operation.
  // * Space Complexity: O(1).
  // * Pros: Very fast, elegant for positive integers.
  // ! Cons: Doesn't handle n=0 (log10(0) is undefined), may have precision issues for very large n.
  // ? Note: Cast to int truncates towards zero.

  // int count = (int)log10(n) + 1;
}