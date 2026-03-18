#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Brute Force
   * Generate all possible subarrays and count the number of subarrays whose sum equals to goal.
   * TC: O(n^2)
   * SC: O(1)
   */
  // int numSubarraysWithSum(vector<int>& nums, int goal) {
  //   int count = 0;
  //   for (int i = 0; i < nums.size(); i++) {
  //     int sum = 0;
  //     for (int j = i; j < nums.size(); j++) {
  //       sum += nums[j];
  //       if (sum == goal) {
  //         count++;
  //       }
  //     }
  //   }
  //   return count;
  // }

  /** Approach 2: Sliding Window + two pointers
   * Direct sliding window for sum == goal fails because zeros allow multiple
   * valid subarrays ending at the same index. A single window only tracks one
   * left boundary, so it misses other valid starting points.
   *
   * Instead of counting subarrays with sum == goal directly, compute:
   *
   *     subarrays with sum == goal
   *   = subarrays with sum <= goal
   *   - subarrays with sum <= goal - 1
   *
   * Now the task becomes counting subarrays whose sum is <= k.
   *
   * For each right pointer:
   *  - expand the window by adding nums[right]
   *  - shrink from the left while sum > k
   *  - once sum <= k, every subarray ending at right and starting from any
   *    index between left and right is valid.
   *
   * Number of such subarrays = (right - left + 1)
   *
   * This works because the array is binary, so expanding increases the sum
   * by at most 1 and shrinking always decreases it, making the window stable.
   *
   * TC: O(n)
   * SC: O(1)
   */

  int count_subarrays(vector<int>& nums, int goal) {
    if (goal < 0) return 0;

    int left, right;
    left = right = 0;
    int sum = 0;
    int count = 0;
    while (right < nums.size()) {
      sum += nums[right];
      while (sum > goal) {
        sum -= nums[left];
        left++;
      }
      if (sum <= goal) {
        count += right - left + 1;
      }
      right++;
    }

    return count;
  }
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return count_subarrays(nums, goal) - count_subarrays(nums, goal - 1);
  }

  /** Approach 3: Prefix Sum + Hash Map
   * Let prefix_sum[i] represent the sum of elements from index 0 to i.
   * The sum of a subarray (l..r) can be written as:
   *
   *     subarray_sum = prefix_sum[r] - prefix_sum[l-1]
   *
   * For this subarray to equal goal:
   *
   *     prefix_sum[r] - prefix_sum[l-1] = goal
   *     prefix_sum[l-1] = prefix_sum[r] - goal
   *
   * While iterating through the array we maintain the current prefix_sum.
   * If a previous prefix_sum equal to (prefix_sum - goal) exists, it means
   * there is a subarray ending at the current index whose sum equals goal.
   *
   * A hashmap stores how many times each prefix_sum has appeared so far.
   * For every element:
   *  - update prefix_sum
   *  - check if (prefix_sum - goal) exists in the map
   *  - add its frequency to the answer
   *  - record the current prefix_sum in the map
   *
   * prefix_sum_count[0] = 1 handles cases where a valid subarray starts
   * from index 0.
   *
   * TC: O(n)
   * SC: O(n)
   */
  // int numSubarraysWithSum(vector<int>& nums, int goal) {
  //   unordered_map<int, int> prefix_sum_count;
  //   prefix_sum_count[0] = 1;  // Base case: one way to have a sum of 0 (empty subarray)
  //   int prefix_sum = 0, count = 0;
  //   for (int num : nums) {
  //     prefix_sum += num;
  //     // Check if there is a prefix sum that would make the current sum equal to goal
  //     if (prefix_sum_count.find(prefix_sum - goal) != prefix_sum_count.end()) {
  //       count += prefix_sum_count[prefix_sum - goal];
  //     }
  //     // Record the current prefix sum count
  //     prefix_sum_count[prefix_sum]++;
  //   }

  //   return count;
  // }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  Solution sol;

  while (t--) {
    int n, goal;
    cin >> n >> goal;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }

    int result = sol.numSubarraysWithSum(nums, goal);
    cout << result << "\n";
  }
  return 0;
}