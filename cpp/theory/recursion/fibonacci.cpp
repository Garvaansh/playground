#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << sol.fib(n) << "\n";
  }

  return 0;
}