#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

class Solution {
 public:
  /** Approach 1:  Brute Force
   * simple iterate over all possible submatrices and
   * check if the sum of the elements in the submatrix is less than k. If it is, increment the
   * count.
   * TC: O(m^2 * n^2)
   * SC: O(1)
   */

  // int countSubmatrices(matrix& grid, int k) {
  //   int count = 0;
  //   int m = grid.size();
  //   int n = grid[0].size();
  //   for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //       int sum = 0;

  //       for (int x = 0; x <= i; x++) {
  //         for (int y = 0; y <= j; y++) {
  //           sum += grid[x][y];
  //         }
  //       }

  //       if (sum < k) count++;
  //     }
  //   }
  //   return count;
  // }

  /** Approach 2: Prefix Sum
   * Intuition: build a prefix sum matrix where prefix[i][j] is
   * the sum of the elements in the submatrix from (0, 0) to (i, j).
   * Then, for each submatrix defined by its top element (i - 1, j) and left element (i, j - 1),
   * Subtract the repetitive sum by using diagonal (i - 1, j - 1).
   * we can calculate the sum of the elements in that submatrix using the prefix sums.
   * If the sum is less than k, we increment the count.
   * TC: O(m * n)
   * SC: O(m * n) for the prefix sum matrix
   */
  int countSubmatrices(matrix& grid, int k) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();

    matrix prefix(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        prefix[i][j] = grid[i][j];

        if (i > 0) prefix[i][j] += prefix[i - 1][j];
        if (j > 0) prefix[i][j] += prefix[i][j - 1];
        if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];

        if (prefix[i][j] > k) break;
        count++;
      }
    }
    return count;
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
    int m, n, k;
    cin >> m >> n >> k;
    matrix grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }

    cout << sol.countSubmatrices(grid, k) << "\n";
  }

  return 0;
}