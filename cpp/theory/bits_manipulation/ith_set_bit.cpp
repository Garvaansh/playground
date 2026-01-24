#include <bits/stdc++.h>
using namespace std; 

bool set_bit(int n, int pos) {
  // Approach 1: Check if i-th bit is set using AND with shifted 1
  // (n & (1 << pos)) != 0 checks if bit at pos is 1.
  // Alternatively, (n >> pos) & 1 shifts and checks LSB.
  // Example: n=5 (101), pos=0
  // 1 << 0 = 001
  // 101 & 001 = 001 != 0, true
  // n >> 0 & 1 = 101 & 1 = 1, true
  // pos=1: 101 & 010 = 000 == 0, false
  // Time: O(1)
  // Space: O(1)
  return (n & ( 1 << pos )) != 0;

  // Right shift operator
  // return (n >> pos) & 1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, pos;
    cin >> n >> pos;
    if (set_bit(n, pos)) {
      cout << "SET BIT\n";
    } else {
      cout << "NOT SET BIT\n";
    }
  }

    return 0;
}