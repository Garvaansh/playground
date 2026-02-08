#include <bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n){
  // * Approach 1: Brute Force
  // * Logic: Loop from 1 to n, check if i divides n, add i to the vector.
  // * This checks every possible divisor up to n.
  // * Time Complexity: O(n) - loop runs n times.
  // * Space Complexity: O(d) where d is number of divisors.
  // * Pros: Simple to understand, works for all n.
  // ! Cons: Inefficient for large n, as it checks every number.
  // ? Note: No need for sorting since divisors are added in order.
  /*
  vector<int> arr;
  for(int i = 1; i <= n; i++) {
      if(n % i == 0) {
          arr.push_back(i);
      }
  }
  return arr;
  */

    // * Approach 2: Efficient divisor finding using square root optimization
    // * Logic: Loop from 1 to sqrt(n), check if i divides n, add i and n/i (if different) to collect all pairs.
    // * This ensures we find all divisors without checking every number up to n.
    // * Time Complexity: O(sqrt(n)) - loop runs up to sqrt(n) times.
    // * Space Complexity: O(d) where d is number of divisors (stored in vector).
    // * Pros: Much faster than O(n) for large n, handles perfect squares correctly.
    // ! Cons: Requires sorting at the end if order matters, but divisors are naturally paired.
    // ? Note: For n=1, divisors are [1]; for primes, only [1, n].
    vector<int> arr;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            arr.push_back(i);
            if(i != (n/i)) arr.push_back(n/i);
            }
    }
    sort(arr.begin(), arr.end());
    return arr; 

}

int main() {
    int n;
    cin >> n;
    vector<int> res = printDivisors(n);
    for(auto x: res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}