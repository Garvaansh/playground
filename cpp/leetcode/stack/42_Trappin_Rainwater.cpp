#include <bits/stdc++.h>
using namespace std; 

/** Trapping Rain Water
 * ? Calculates total water trapped between bars in height array
 * ! Uses prefix and suffix max arrays to find water at each position
 * ! Time: O(n), Space: O(n) for prefix and suffix arrays
 */

class Solution {
  public:
    //* Computes prefix max: max height from left to current index
    vector<int> PrefMax(vector<int>& height) {
      vector<int> PrefixMax(height.size());
      for(int i = 0; i < height.size(); i++) {
        PrefixMax[i] = (i > 0) ? max(PrefixMax[i - 1], height[i]) : height[i];
      }
      return PrefixMax;
    }
    //* Computes suffix max: max height from right to current index
    vector<int> SuffMax(vector<int>& height) {
      vector<int> SuffixMax(height.size());
      for(int i = height.size() - 1; i >= 0; i--) {
        SuffixMax[i] = (i < height.size() - 1) ? max(SuffixMax[i + 1], height[i]) : height[i];
      }
      return SuffixMax;
    }

    //* Main function: compute prefix/suffix max, sum trapped water
    int trap(vector<int>& height) {
      int total = 0;
      vector<int> PrefixMax = PrefMax(height);
      vector<int> SuffixMax = SuffMax(height);
      //* For each bar, water = min(left_max, right_max) - height
      for(int i = 0; i < height.size(); i++) {
        total += min(PrefixMax[i], SuffixMax[i]) - height[i];
      }
      return total;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) cin >> height[i];
    cout << Solution().trap(height) << endl;
  }
    return 0;
}