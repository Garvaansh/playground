#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Brute  Force
   * Scan through the array and generate all possible subaarays
   * For each subaaray if k exceeds, then break and move to next subaaray
   * TC: O(n^2)
   * SC: O(1)
   */
  // int longestOnes(vector<int>& nums, int k) {
  //   int Maxlen = 0;
  //   for (int i = 0; i < nums.size(); i++) {
  //     int len = 0, zero_cnt = 0;
  //     for (int j = i; j < nums.size(); j++) {
  //       if (nums[j] == 0) zero_cnt++;
  //       if (zero_cnt > k) break;
  //       len++;
  //     }
  //     Maxlen = max(Maxlen, len);
  //   }
  //   return Maxlen;
  // }

  /** Approach 2: Sliding  Window + Two pointers
   * Use two pointers to maintain a window of 1s and at most k 0s
   * If zeros_count  > k, then shrink from left until zeros_count <= k
   * TC: O(n) + O(n) = O(2n)
   * SC: O(1)
   */
  // int longestOnes(vector<int>& nums, int k) {
  //   int maxLen = 0, left = 0, right = 0, zeroCnt = 0;
  //   while (right < nums.size()) {
  //     if (nums[right] == 0) zeroCnt++;
  //     while (zeroCnt > k) {
  //       if (nums[left] == 0) zeroCnt--;
  //       left++;
  //     }
  //     maxLen = max(maxLen, right - left + 1);
  //     right++;
  //   }
  //   return maxLen;
  // }

  /** Approach 3: Sliding  Window + Two pointers (Optimized)
   * Use two pointers to maintain a window of 1s and at most k 0s
   * If zeros_count  > k, then shrink from left until zeros_count <= k
   * Instead of using while loop to shrink from left,
   *  we can directly move left pointer to the next position of the first 0 in the current window
   * TC: O(n)
   * SC: O(1)
   */
  int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0, left = 0, right = 0, zeroCnt = 0;
    while (right < nums.size()) {
      if (nums[right] == 0) zeroCnt++;
      if (zeroCnt > k) {
        if (nums[left] == 0) zeroCnt--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
      right++;
    }

    return maxLen;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    cout << Solution().longestOnes(nums, k) << endl;
  }

  return 0;
}