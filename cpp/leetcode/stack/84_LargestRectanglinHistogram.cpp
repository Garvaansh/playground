#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    /** Approach 1: Brute force. 
     * ! TC :O(n^2)
    */
    // int largestRectangleArea(vector<int>& heights) {
    //   int max_area = 0;
    //   for(int i = 0; i < heights.size(); i++) {
    //     int curr_area = 0;
    //     int m, n;
    //     m = n = i;
    //     while(m > 0 && heights[m - 1] >= heights[i])  m--;
    //     while(n < heights.size() - 1 && heights[n + 1] >= heights[i]) n++;
    //     int k = n - m + 1;
    //     curr_area = heights[i] * k;
    //     max_area = max(max_area, curr_area);
    //   }
    //   return max_area;
    // }


    /** Approach 2: Using Next/Prev Smaller Element (index-based)
     * ! Exact work: three linear passes over the array (compute NSE, compute PSE, compute areas) -> ~3*n steps
     * ! Time (exact count approx): O(3n) amortized (amortized due to stack pops), Space: O(n)
     */
    // //* Compute Next Smaller Element (NSE) indices: for each i, index of first smaller to the right or n
    // vector<int> NextSmallerElement(vector<int>& heights) {
    //   stack<int> st;                         // store indices of an increasing stack
    //   vector<int> res(heights.size());      // result holds next-smaller index for each position
    //   for(int i = heights.size()- 1; i >= 0; i--) {
    //     while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
    //     res[i] = st.empty() ? heights.size() : st.top();
    //     st.push(i);                          // push current index for future comparisons
    //   }
    //   return res;
    // }

    // //* Compute Previous Smaller Element (PSE) indices: for each i, index of first smaller to the left or -1
    // vector<int> PrevSmallerElement(vector<int>& heights) {
    //   stack<int> st;                         // store indices of an increasing stack
    //   vector<int> res(heights.size());      // result holds previous-smaller index for each position
    //   for(int i = 0; i < heights.size(); i++) {
    //     while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
    //     res[i] = st.empty() ? -1 : st.top();
    //     st.push(i);                          // push current index for future comparisons
    //   }
    //   return res;
    // }

    // //* Area computation: width for bar i is (NSE[i] - PSE[i] - 1); compute area and track max
    // int largestRectangleArea(vector<int>& heights) {
    //   vector<int> NextSmaller = NextSmallerElement(heights);
    //   vector<int> PrevSmaller = PrevSmallerElement(heights);
    //   int max_area = 0;
    //   for(int i = 0; i < heights.size(); i++) {
    //     int width = NextSmaller[i] - PrevSmaller[i] - 1; // number of contiguous bars >= heights[i]
    //     int area = heights[i] * width;                   // area with heights[i] as limiting height
    //     max_area = max(max_area, area);
    //   }
    //   return max_area;
    // }

    /**  Approach 3: Using single stack (single-pass, index-based)
     * ? Process indices left-to-right; push increasing heights' indices and compute rectangles when a lower bar appears
     * ! Exact work: one loop of n+1 iterations plus up to n stack pops -> ≈ 2n primitive push/pop operations => O(2n + 1) exact, amortized O(n)
     */
    int largestRectangleArea(vector<int>& heights) {
      stack<int> st;                            // store indices of bars in increasing height order
      int max_area = 0;
      for(int i = 0; i <= heights.size(); i++) {
        // When current bar is lower than stack top (or we reached sentinel i==n), compute area
        while(!st.empty() && (i == heights.size() || heights[i] < heights[st.top()])) {
          int height = heights[st.top()];       // height of the bar that limits the rectangle
          st.pop();                             // remove it to find the span where it's minimum
          int width = st.empty() ? i : i - st.top() - 1; // width between previous smaller and current index
          max_area = max(max_area, height * width);     // update global maximum area
        }
        st.push(i);                              // push current index as candidate for future rectangles
      }
      return max_area;                          // final maximal rectangle area
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++) cin >> heights[i];
    cout << Solution().largestRectangleArea(heights) << endl;
  }

    return 0;
}