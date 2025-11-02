#include <bits/stdc++.h>
using namespace std; 


vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n + 1, 1);
  primes[0] = primes[1] = 0; // 0 and 1 are not prime numbers

  // * Approach 1: Extreme Brute Force
  // * Logic: For each i from 2 to n, if prime, mark all multiples starting from 2*i.
  // * This is the basic sieve but less optimized due to earlier marking.
  // * Time Complexity: O(n log log n) still, but with more operations.
  // * Space Complexity: O(n).
  // * Pros: Simpler to understand.
  // ! Cons: Slightly slower and more redundant than optimized version.
  // ? Note: Commented for comparison; use optimized for performance.
  /*
  for(int i = 2; i <= n; i++) {
    if(primes[i]) {
      for(int j = 2 * i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }
  */

  // * Approach 2: Optimized Sieve 
  // * Logic: Use a boolean array to mark composites; for each prime i, mark multiples starting from i*i.
  // * This avoids redundant checks by starting marking from i*i instead of 2*i.
  // * Time Complexity: O(n log log n) - highly efficient for large n.
  // * Space Complexity: O(n) - boolean array of size n+1.
  // * Pros: Fastest for generating primes up to n; standard algorithm.
  // ! Cons: Memory-intensive for very large n.
  // ? Note: Returns list of primes; sieve up to n inclusive.
  for(int i = 2; i * i <= n; i++) {
    if(primes[i]) {
      for(int j = i * i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }

  vector<int> result;
  for(int i = 2; i <= n; i++) {
    if(primes[i]) {
      result.push_back(i);
    }
  }
  return result;

}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> primes = sieve_of_eratosthenes(n);
    for(int p : primes) {
      cout << p << " ";
    }
    cout << "\n";
  }

  return 0;
}