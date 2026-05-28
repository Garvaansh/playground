#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 1) return true;
    if (n <= 0 || ((n % 3) != 0)) return false;
    return isPowerOfThree(n / 3);
  }
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

  cout << sol.isPowerOfThree(27) << "\n";  // true

  return 0;
}