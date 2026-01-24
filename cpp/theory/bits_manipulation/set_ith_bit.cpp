#include <bits/stdc++.h>
using namespace std; 

int set_ith_bit(int n, int pos) {
  // Approach 1: OR with shifted 1
  // n | (1 << pos) sets the bit at pos to 1.
  // Example: n=5 (101), pos=1
  // 1 << 1 = 010
  // 101 | 010 = 111 (7)
  // Time: O(1)
  // Space: O(1)
  return n | ( 1 << pos );
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, pos;
    cin >> n >> pos;
    cout << set_ith_bit(n, pos) << "\n";
    }

    return 0;
}