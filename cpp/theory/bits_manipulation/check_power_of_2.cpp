#include <bits/stdc++.h>
using namespace std; 

int pow_of_2(int n) {
  // Approach 1: Check if n & (n-1) == 0
  // Powers of 2 have exactly one set bit; n & (n-1) clears the lowest set bit.
  // Example: n=4 (binary 100)
  // n-1=3 (011)
  // 100 & 011 = 000, so true
  // n=5 (101)
  // n-1=4 (100)
  // 101 & 100 = 100 !=0, so false
  // Time: O(1)
  // Space: O(1)
  return (n & (n - 1)) == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << pow_of_2(n) << "\n";
    }

    return 0;
}