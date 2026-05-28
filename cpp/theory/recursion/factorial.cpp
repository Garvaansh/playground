#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int factorial(int n) {
      if (n == 1) return 1;
      return n * factorial(n - 1); 
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
  //   cout << sol.factorial(n) << "\n";
  // }

  cout << sol.factorial(5) << "\n"; // Output: 120

  return 0;
}