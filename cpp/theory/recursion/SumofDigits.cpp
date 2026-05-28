#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int Sum(int n) {
      if (n <= 1) return n;
      return Sum(n / 10) + (n % 10);
    }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  cout << sol.Sum(123) << "\n"; // Output: 6

  return 0;
}