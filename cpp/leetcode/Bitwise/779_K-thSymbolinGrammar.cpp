// Similar to problem : cpp/leetcode/strings/1545_FindKthBitinNthBinaryString.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // values
  // #1                         0
  // #2            0                        1
  // #3      0           1            1             0
  // #4   0    1      1     0       1   0        0    1
  // #5 0  1  1  0  1  0  0  1    1  0  0  1   0  1  1  0

  // element 1-based index
  // #1                 1
  // #2        1                   2
  // #3   1         2         3         4
  // #4 1   2     3   4     5   6     7   8

  /**
   * Intuition: Each row is formed as prev + flip(prev), so for row n,
   * the string is S_{n-1} + !S_{n-1};
   * the k-th symbol depends on whether k is in the first or second half.
   * Approach: Recursively check if k is in the first half (same as parent) or second half (flip
   * parent's value), reducing the problem to a smaller row each time. 
   * TC: O(n) — one recursive call per row. 
   * SC: O(n) — recursion stack for n levels.
   */
  int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    int half = 1 << (n - 2);

    if (k <= half)
      return kthGrammar(n - 1, k);
    else
      return 1 - kthGrammar(n - 1, k - half);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    Solution sol;
    cout << sol.kthGrammar(n, k) << endl;
  }

  return 0;
}