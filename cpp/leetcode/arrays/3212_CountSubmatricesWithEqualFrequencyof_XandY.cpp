#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<char>> vvc;
typedef vector<vector<int>> vvi;

class Solution {
 public:
  /** Approach 1: Prefix Sum (brute force)
   * Intuition: Convert the grid into a numerical representation where 'X' is 1, 'Y' is -1, and
   * other characters are 0. Build prefix sum and count matrices to calculate the sum of submatrices
   * efficiently. Check if the sum of the submatrix is zero and the count of 'X' is greater than zero.
   * TC: O(2(m * n)) for iterating over all submatrices
   * SC: O(m * n) for prefix sum and count matrices
   */
  // int numberOfSubmatrices(vector<vector<char>>& grid) {
  //     int m = grid.size(), n = grid[0].size();
  //     int count = 0;
  //     vvi b_grid(m, vector<int>(n, 0));

  //     vvi prefix(m, vector<int>(n, 0));
  //     vvi xCount(m, vector<int>(n, 0));

  //     for(int i = 0; i < m; i++) {
  //         for(int j = 0; j < n; j++) {
  //             if (grid[i][j] == 'X') b_grid[i][j] = 1;
  //             else if (grid[i][j] == 'Y') b_grid[i][j] = -1;
  //             else b_grid[i][j] = 0;
  //         }
  //     }

  //     // Build prefixSum and xCount matrix
  //     for(int i = 0; i < m; i++) {
  //         for(int j = 0; j < n; j++) {
  //                 // Increment xcount if 'x' is seen
  //                 if (b_grid[i][j] == 1)
  //                     xCount[i][j] += 1;

  //                 prefix[i][j] = b_grid[i][j];

  //                 if (i > 0) {
  //                     xCount[i][j] += xCount[i - 1][j];
  //                     prefix[i][j] += prefix[i - 1][j];
  //                     }
  //                 if (j > 0) {
  //                 xCount[i][j] += xCount[i][j - 1];
  //                 prefix[i][j] += prefix[i][j - 1];
  //                     }
  //                 if (i > 0 && j > 0) {
  //                 xCount[i][j] -= xCount[i - 1][j - 1];
  //                 prefix[i][j] -= prefix[i - 1][j - 1];
  //                     }

  //                 if (prefix[i][j] == 0 && xCount[i][j] > 0) count++;
  //         }
  //     }

  //     return count;
  // }

  /** Approach 2: Prefix Sum (optimized)
   * Intuition: Use prefix sum matrices to count occurrences of 'X' and 'Y' in submatrices.
   * For each submatrix, calculate the count of 'X' and 'Y' using prefix sums.
   * If the counts are equal and greater than zero, increment the count.
   * TC: O(m * n) for building prefix sum matrices and iterating over the grid
   * SC: O(m * n) for prefix sum matrices
   */
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size(), n = grid[0].size();

    vvi countX(m, vector<int>(n, 0));
    vvi countY(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        countX[i][j] = (grid[i][j] == 'X');
        countY[i][j] = (grid[i][j] == 'Y');

        if (i > 0) {
          countX[i][j] += countX[i - 1][j];
          countY[i][j] += countY[i - 1][j];
        }

        if (j > 0) {
          countX[i][j] += countX[i][j - 1];
          countY[i][j] += countY[i][j - 1];
        }

        if (i > 0 && j > 0) {
          countX[i][j] -= countX[i - 1][j - 1];
          countY[i][j] -= countY[i - 1][j - 1];
        }

        if (countX[i][j] == countY[i][j] && countX[i][j] > 0) {
          count++;
        }
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
    int m, n;
    cin >> m >> n;
    vvc grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> grid[i][j];
      }
    }

    int result = sol.numberOfSubmatrices(grid);
    cout << result << "\n";
  }

  return 0;
}