#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int steps(int num, int count) {
    if (num == 0) return count;

    if (num % 2 == 0) return steps(num >> 1, count + 1);
    return steps(num - 1, count + 1);
  }

  int numberOfSteps(int num) { 
    return steps(num, 0); 
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
    int num;
    cin >> num;
    cout << sol.numberOfSteps(num) << endl;
  }

  return 0;
}