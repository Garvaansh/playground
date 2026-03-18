#include <bits/stdc++.h>
using namespace std;

using matrix_int = vector<vector<int>>;
using matrix_char = vector<vector<char>>;

class Solution {
 public:
  /** Monotonic stack approach for largest rectangle in histogram
   * ? Logic: Maintain a stack of indices whose bar heights are in increasing order.
   * ? When current index `i` sees a lower height, pop the stack and compute the
   * ? area with the popped height as the limiting bar. Width is the distance
   * ? between the previous smaller bar (stack top after pop) and `i`.
   * ! Time Complexity: O(n) — each index is pushed and popped at most once.
   * ! Space Complexity: O(n) worst-case for the stack.
   */
  int largestRectangleArea(vector<int>& heights) {
    stack<int> st;  // store indices of bars in increasing height order
    int max_area = 0;
    for (int i = 0; i <= heights.size(); i++) {
      // When current bar is lower than stack top (or we reached sentinel i==n), compute area
      while (!st.empty() && (i == heights.size() || heights[i] < heights[st.top()])) {
        int height = heights[st.top()];  // height of the bar that limits the rectangle
        st.pop();                        // remove it to find the span where it's minimum
        int width =
            st.empty() ? i : i - st.top() - 1;  // width between previous smaller and current index
        max_area = max(max_area, height * width);  // update global maximum area
      }
      st.push(i);  // push current index as candidate for future rectangles
    }
    return max_area;  // final maximal rectangle area
  }

  /** Maximal rectangle in binary matrix via row-wise histograms
   * ? Logic: For each row compute the column-wise height of consecutive '1's
   * ? (treat row as base of a histogram). For every row, call the histogram
   * ? solver (`largestRectangleArea`) to get the largest rectangle using that row
   * ? as the bottom. Keep the maximum across all rows.
   * ! Time Complexity: O(n * m) where n = number of rows and m = number of cols;
   * ! we build heights in O(n*m) and run an O(m) histogram solver per row.
   * ! Space Complexity: O(m) for the prefix/heights array plus stack space.
   */
  int maximalRectangle(matrix_char& mat) {
    int maxArea = 0;
    int n = mat.size();
    int m = mat[0].size();
    matrix_int prefixSum(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (mat[i][j] == '1') {
          if (i > 0)
            prefixSum[i][j] = prefixSum[i - 1][j] + 1;
          else
            prefixSum[i][j] = 1;
        } else {
          prefixSum[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
    }
    return maxArea;
  }
};

/**
 * Instead of using a prefixSum matrix,
 * we could use a simple row wise iteration that handle the prefix sum
 * vector<int> heights(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '1')
                heights[j] += 1;
            else
                heights[j] = 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
 */

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    matrix_char mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        cin >> mat[i][j];
    }
    cout << Solution().maximalRectangle(mat) << endl;
  }

  return 0;
}