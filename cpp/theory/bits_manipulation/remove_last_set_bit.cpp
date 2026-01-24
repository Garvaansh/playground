#include <bits/stdc++.h>
using namespace std; 

int remove_last_set_bit(int n) {
  // Approach 1: AND with n-1
  // n & (n-1) clears the rightmost set bit.
  // Example: n=5 (101)
  // n-1=4 (100)
  // 101 & 100 = 100 (4)
  // Time: O(1)
  // Space: O(1)
  return (n & (n - 1));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << remove_last_set_bit(n) << "\n";
    }

    return 0;
}