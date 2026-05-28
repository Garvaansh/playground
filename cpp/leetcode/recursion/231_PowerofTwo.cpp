#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool chkpow(int n) {
    if (n == 1) return true;
    if (n <= 0) return false;
    if (n & 1) return false;
    return chkpow(n / 2);
  }

  bool isPowerOfTwo(int n) { return chkpow(n); }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  // int t;
  // cin >> t;
  // while (t--) {
  //   int n;
  //   cin >> n;
  //   cout << sol.isPowerOfTwo(n) << "\n";
  // }

  cout << sol.isPowerOfTwo(16) << "\n";  // true

  return 0;
}