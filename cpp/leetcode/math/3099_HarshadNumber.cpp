#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    auto sum = [&](int x) {
      int temp = x;
      int total = 0;
      while (temp != 0) {
        total += temp % 10;
        temp /= 10;
      }
      return total;
    };
    int s = sum(x);
    return (x % s == 0) ? s : -1;
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  Solution sol;
  while (t--) {
    int x;
    cin >> x;
    cout << sol.sumOfTheDigitsOfHarshadNumber(x) << "\n";
  }

  return 0;
}