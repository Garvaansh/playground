#include <bits/stdc++.h>
using namespace std; 

int toggle_ith_bit(int n, int pos) {
  // Approach 1: XOR with shifted 1
  // n ^ (1 << pos) flips the bit at pos.
  // Example: n=5 (101), pos=0
  // 1 << 0 = 001
  // 101 ^ 001 = 100 (4)
  // Time: O(1)
  // Space: O(1)
  return (n ^ (1 << pos));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, pos;
    cin >> n >> pos;
    cout << toggle_ith_bit(n, pos) << "\n";
    }

    return 0;
}