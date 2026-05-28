#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Recursion approach 1: Mutate parameters and single recursive call
   * ! Disadvante: complex problems may lead to confusion and bugs due to parameter mutation
   */
  // int BS(vector<int>& nums, int target, int low, int high) {
  //   if (low > high) return -1;
  //   int mid = low + (high - low) / 2;
  //   if (nums[mid] == target) return mid;

  //   if (nums[mid] > target)
  //     high = mid - 1;
  //   else
  //     low = mid + 1;

  //   return BS(nums, target, low, high);
  // }

  /** Recursion approach 2: No parameter mutation and multiple recursive calls
   * ? Advante: clearer and easier to debug, but may lead to more recursive calls and
   * ? increased time complexity in some cases
   */
  int BS(vector<int>& nums, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (nums[mid] == target) return mid;

    if (nums[mid] > target) return BS(nums, target, low, mid - 1);
    return BS(nums, target, mid + 1, high);
  }

  int search(vector<int>& nums, int target) { return BS(nums, target, 0, nums.size() - 1); }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  // int t;
  // cin >> t;
  // while (t--) {
  //   int n, target;
  //   cin >> n >> target;
  //   vector<int> nums(n);
  //   for (int i = 0; i < n; ++i) {
  //     cin >> nums[i];
  //   }
  // }

  vector<int> nums = {1, 2, 4, 65, 67, 78};
  int target = 67;
  cout << sol.search(nums, target) << "\n";

  return 0;
}