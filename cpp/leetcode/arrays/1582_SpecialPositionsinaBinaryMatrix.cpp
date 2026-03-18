#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach: while iterating, keep a count of 1 for each row and it's respoective column
   * TC: O(m*n) where m is the number of rows and n is the number of columns in the matrix
   * SC: O(m+n) where m is the number of rows and n is the number of columns in the matrix
   */
  int numSpecial(vector<vector<int>>& mat) {
    vector<int> row(mat.size()), col(mat[0].size());
    int count = 0;

    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (mat[i][j] == 1) {
          row[i]++;
          col[j]++;
        }
      }
    }

    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
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

  Solution sol;

  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
      }
    }

    cout << sol.numSpecial(mat) << "\n";
  }

  return 0;
}