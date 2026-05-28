#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**
   * Approach 1 : Monotonic stack using NGE concept
   * Intuition: Precompute for each index the next greater element (NGE) to the right, then jump
   * through NGEs to find the max in each window efficiently. For each window, start at the left and
   * keep jumping to the next greater index until you exit the window; the last index visited is the
   * max. Time Complexity: O(n) — both NGE computation and window queries are linear in total. Space
   * Complexity: O(n) — extra arrays and stack for NGE and results.
   */

  //   vector<int> NextGreaterElement(vector<int>& nums) {
  //     vector<int> res(nums.size());
  //     stack<int> st;
  //     for (int i = nums.size() - 1; i >= 0; i--) {
  //       while (!st.empty() && nums[i] >= nums[st.top()])
  //         st.pop();
  //       res[i] = st.empty() ? -1 : st.top();
  //       st.push(i);
  //     }
  //     return res;
  //   }

  //   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  //     vector<int> NGE = NextGreaterElement(nums);
  //     vector<int> res;
  //     for (int i = 0; i <= nums.size() - k; i++) {
  //       int j = i;
  //       while (NGE[j] != -1 && NGE[j] < i + k)
  //         j = NGE[j];
  //       res.push_back(nums[j]);
  //     }
  //     return res;
  //   }

  /* ---------------------------------------------------------------------------------------------------------------
   */

  /**
   * Approach 2 : Using Deque
   * Intuition: Maintain a deque of indices for elements in decreasing order of value, so the
   * front always gives the max for the current window. For each new element, remove indices out
   * of window and those with smaller values from the back, then add current index; window max
   * is at the front. Time Complexity: O(n) — each index is pushed and popped from the deque at
   * most once. Space Complexity: O(k) — deque holds at most k indices at any time.
   */
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    vector<int> res = Solution().maxSlidingWindow(nums, k);
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
      cout << res[i];
      if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}