#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Intuition: For each row, count trailing zeros to check if it can satisfy the grid condition
   * after swaps. Approach: For each position, greedily bubble up a row with enough trailing zeros
   * by adjacent swaps; count total swaps needed. Time Complexity: O(n^2) — each row may be swapped
   * up to n times. Space Complexity: O(n) — extra array for trailing zeros.
   */
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    // Calculates the trailing zeros in each row
    vector<int> TrailZero(n, 0);

    for (int i = 0; i < n; i++) {
      int cnt = 0, k = n - 1;
      while (k >= 0 && grid[i][k] == 0) {
        cnt++;
        k--;
      }
      TrailZero[i] = cnt;
    }

    // Greedy Bubble sort the rows based on the number of trailing zeros
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int j = i;
      /**
       * for row 1 there'll be m - 1 trailing zeros,
       * for row 2 there'll be m - 2 trailing zeros,
       * for row 3 there'll be m - 3 trailing zeros, and so on...
       * so for row i there should be at least n - 1 - i trailing zeros
       */
      while (j < n && TrailZero[j] < n - 1 - i) {
        j++;
      }

      if (j == n) return -1;

      ans += j - i;

      while (j > i) {
        swap(TrailZero[j], TrailZero[j - 1]);
        j--;
      }
    }

    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    cout << Solution().minSwaps(grid) << endl;
  }

  return 0;
}