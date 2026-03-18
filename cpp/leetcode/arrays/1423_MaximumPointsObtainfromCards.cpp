#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Intuition: Try all ways to pick cards from both ends by sliding a window of size k over the two ends.
   * Approach: Start with the first k cards, then for each step, swap one card from the left with one from the right, tracking the max sum.
   * Time Complexity: O(2*k) — only k window shifts are needed.
   * Space Complexity: O(1) — uses a few variables for sums.
   */
  int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0, rightSum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) leftSum += cardPoints[i];
    maxSum = leftSum;

    int r = cardPoints.size() - 1;
    for (int i = k - 1; i >= 0; i--) {
      leftSum -= cardPoints[i];
      rightSum += cardPoints[r--];
      maxSum = max(maxSum, leftSum + rightSum);
    }
    return maxSum;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> cardPoints(n);
    for (int i = 0; i < n; i++) {
      cin >> cardPoints[i];
    }

    cout << Solution().maxScore(cardPoints, k) << endl;
  }

  return 0;
}