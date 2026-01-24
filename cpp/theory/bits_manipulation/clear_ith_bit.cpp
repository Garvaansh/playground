#include <bits/stdc++.h>
using namespace std; 

int clear_ith_bit(int n, int pos) {
  // Approach 1: Use AND with NOT of shifted 1
  // ~(1 << pos) creates a mask with 0 at pos, 1 elsewhere; AND clears the bit.
  // Example: n=5 (101), pos=0
  // 1 << 0 = 001
  // ~(001) = ...110 (in 3 bits)
  // 101 & 110 = 100 (4)
  // Time: O(1)
  // Space: O(1)
  return (n & (~(1 << pos)));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, pos;
    cin >> n >> pos;
    cout << clear_ith_bit(n, pos) << "\n";
    }

    return 0;
}