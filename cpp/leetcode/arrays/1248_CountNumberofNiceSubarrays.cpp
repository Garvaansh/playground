#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Prefix Sum + Hash Map
   * Instead of summing values, track how many odd numbers have appeared so far.
   * Let prefixOdd represent the number of odd elements from index 0 → current index.
   *
   * For a subarray (l..r) to contain exactly k odd numbers:
   *
   *     prefixOdd[r] - prefixOdd[l-1] = k
   *
   * Rearranging:
   *
   *     prefixOdd[l-1] = prefixOdd[r] - k
   *
   * While scanning the array, maintain a hashmap that stores how many times
   * each prefixOdd value has appeared. At every index:
   *
   *   1. Update prefixOdd if the current element is odd.
   *   2. Check if (prefixOdd - k) exists in the map.
   *      If it does, all those occurrences represent valid subarrays ending here.
   *   3. Add the current prefixOdd to the hashmap.
   *
   * mp[0] = 1 is initialized to handle subarrays that start from index 0.
   *
   * TC: O(n)
   * SC: O(n)
   */
  // int numberOfSubarrays(vector<int>& nums, int k) {
  //     unordered_map<int,int> mp;
  //     mp[0] = 1;

  //     int prefixOdd = 0;
  //     int count = 0;

  //     for (int x : nums) {
  //         prefixOdd += (x & 1);

  //         if (mp.find(prefixOdd - k) != mp.end()) {
  //             count += mp[prefixOdd - k];
  //         }

  //         mp[prefixOdd]++;
  //     }

  //     return count;
  // }

  /** Approach 2: Sliding Window
   * A subarray is considered nice if it contains exactly k odd numbers.
   * Instead of counting subarrays with exactly k odds directly, compute:
   *
   *     subarrays with exactly k odds
   *   = subarrays with at most k odds
   *   - subarrays with at most (k - 1) odds
   *
   * The helper function counts subarrays with at most k odd numbers using
   * a sliding window.
   *
   * Maintain a window [left..right] and track the number of odd elements.
   * For every expansion of right:
   *   - update OddCnt if nums[right] is odd
   *   - shrink the window while OddCnt > k
   *
   * Once the window satisfies OddCnt <= k, every subarray ending at right
   * and starting anywhere between left and right is valid.
   *
   * Number of such subarrays = (right - left + 1)
   *
   * TC: O(n)
   * SC: O(1)
   */

  // Helper function to check if a number is even
  inline bool isOdd(int x) { return (x & 1); }

  int count_subarrays(vector<int>& nums, int k) {
    if (k < 0) return 0;

    int left, right;
    left = right = 0;
    int OddCnt = 0;
    int count = 0;
    while (right < nums.size()) {
      if (isOdd(nums[right])) OddCnt++;
      while (OddCnt > k) {
        if (isOdd(nums[left])) OddCnt--;
        left++;
      }
      if (OddCnt <= k) {
        count += right - left + 1;
      }
      right++;
    }

    return count;
  }

  int numberOfSubarrays(vector<int>& nums, int k) {
    return count_subarrays(nums, k) - count_subarrays(nums, k - 1);
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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }
    int result = sol.numberOfSubarrays(nums, k);
    cout << result << "\n";
  }

  return 0;
}