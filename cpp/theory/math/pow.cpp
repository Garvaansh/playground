#include <bits/stdc++.h>
using namespace std; 

double pow(double x, int m) {
  int n = abs(m);
  double res = 1.0;

  // * Approach 1: Brute Force Multiplication
  // * Logic: Multiply x by itself n times in a loop.
  // * This is the simplest way but inefficient for large n.
  // * Time Complexity: O(n) - n multiplications.
  // * Space Complexity: O(1) - constant space.
  // * Pros: Easy to understand and implement.
  // ! Cons: Very slow for large n; can cause overflow for big results.
  // ? Note: Not recommended for n > 20; doesn't handle n=0 or negative n.
  // for(int i = 1; i <= n; i++) res *= x;
  
  /* -------------------------------------------------------------------------------------------- */
  
  // * Approach 2: Iterative Exponentiation by Squaring
  // * Logic: While n > 0, if n is odd multiply res by x and decrement n; if even square x and halve n.
  // * This reduces multiplications by halving n each time.
  // * Time Complexity: O(log n) - logarithmic in n.
  // * Space Complexity: O(1) - constant space.
  // * Pros: Efficient and fast; avoids recursion stack.
  // ! Cons: Assumes n >= 0; may overflow for large x^n.
  // ? Note: Handles large n well; base case n=0 returns 1 (res=1 initially).
  while(n > 0) {
    if(n % 2 == 1) { // If n is odd
      res *= x;
      n--;
    } else { // If n is even
      x *= x;
      n /= 2;
    }
  }

  /* -------------------------------------------------------------------------------------------- */
  
  // * Approach 3: Recursive Exponentiation by Squaring
  // * Logic: Base case n=0 return 1; if n even, return (x^(n/2))^2; if odd, return x * x^(n-1).
  // * Recursively halves n, multiplying results.
  // * Time Complexity: O(log n) - logarithmic depth.
  // * Space Complexity: O(log n) - recursion stack.
  // * Pros: Clean and mathematical; easy to understand.
  // ! Cons: Recursion depth limit for very large n; stack overflow risk.
  // ? Note: Same efficiency as iterative but uses more space; good for learning recursion.
  // if (n == 0) return 1;
  // if (n % 2 == 0) {
  //   ll int half = pow(x, n / 2);
  //   return half * half;
  // } else {
  //   return x * pow(x, n - 1);
  // }

  return (m < 0) ? 1 / res : res;
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    double x;
    int n;
    cin >> x >> n;
    cout << pow(x, n) << endl;
  }

    return 0;
}