#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

/** Matrix Rotation
 * ! Rotate 90deg clockwise
 * 1. transpose the matrix (swap rows with columns)
 * 2. row reverse
 *
 * ! Rotate 90deg counter-clockwise
 * 1. transpose the matrix (swap rows with columns)
 * 2. column reverse
 *
 */

class Solution {
 public:
  /** Approach 1: Matrix Rotation (Simulation)
   * Intuition: To determine if the matrix can be obtained by rotation, we rotate the matrix up to 4
   * times (0°, 90°, 180°, 270°) and check if it matches the target matrix. Each rotation involves
   * transposing the matrix and then reversing the rows to achieve a 90° rotation. TC: O(n^2) for
   * each rotation, where n is the size of the matrix. Since we perform up to 4 rotations, the total
   * complexity is O(4 * n^2) = O(n^2). SC: O(n^2) for the temporary matrix used during rotation.
   */
  // bool findRotation(Matrix& mat, Matrix& target) {
  //   int n = mat.size();
  //   auto rotate = [&](Matrix& m) {
  //     Matrix temp(n, vector<int>(n));
  //     for (int i = 0; i < n; i++) {
  //       for (int j = 0; j < n; j++) {
  //         temp[j][n - 1 - i] = m[i][j];
  //       }
  //     }
  //     m = temp;
  //   };

  //   for (int k = 0; k < 4; k++) {
  //     if (mat == target) return true;
  //     rotate(mat);
  //   }
  //   return false;
  // }

  /** Approach 2: Matrix Rotation (Transpose and Reverse)
   * Intuition: Instead of creating a temporary matrix for rotation, we can rotate the matrix in-place.
   * First, transpose the matrix by swapping rows with columns. Then, reverse each row to achieve a 90° clockwise rotation.
   * Repeat this process up to 4 times (0°, 90°, 180°, 270°) and check if the matrix matches the target.
   * TC: O(n^2) for each rotation, where n is the size of the matrix. Since we perform up to 4 rotations, the total complexity is O(4 * n^2) = O(n^2).
   * SC: O(1) as the rotation is performed in-place without using extra space.
   */
  bool findRotation(Matrix& mat, Matrix& target) {
    int n = mat.size();

    for (int k = 0; k < 4; k++) {
      if (mat == target) return true;
      // transpose the matrix
      for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
          if (i == j) continue;  // skip diagonal elements
          swap(mat[i][j], mat[j][i]);
        }
      }
      // row reverse
      for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
      }
    }
    return false;
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
    int n;
    cin >> n;
    Matrix mat(n, vector<int>(n));
    Matrix target(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> target[i][j];
      }
    }

    cout << (sol.findRotation(mat, target) ? "true" : "false") << "\n";
  }

  return 0;
}
