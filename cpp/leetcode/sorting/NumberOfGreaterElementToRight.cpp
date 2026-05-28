#include <bits/stdc++.h>
using namespace std; 

/** Count Greater Elements to Right
 * ? Counts for each element how many greater elements are to its right
 * ! Uses modified merge sort: during merge, count inversions where left < right
 * ! Time: O(n log n), Space: O(n) for temp arrays and recursion
 */

class Solution {
  public:
    //* Merge function: combines halves, counts greater elements for left side
    void merge(vector<int>& res, vector<pair<int, int>>& nums, int l, int mid, int r) {
      vector<pair<int, int>> temp(r - l + 1);
      int i = l, j = mid + 1, k = 0;
      //* Merge while counting: if left < right, all remaining right are greater
      while(i <= mid && j <= r) {
        if(nums[i].first < nums[j].first) {
          res[nums[i].second] += (r - j + 1);  //* Add count of remaining right elements
          temp[k++] = nums[i++];
        } else {
          temp[k++] = nums[j++];
        }
      }
      //* Copy remaining left elements
      while(i <= mid) temp[k++] = nums[i++];
      //* Copy remaining right elements
      while(j <= r) temp[k++] = nums[j++];
      //* Copy back to original array
      for(int i = l; i <= r; i++) nums[i] = temp[i - l];
    }

    //* Recursive merge sort: divides array, sorts and merges with counting
    void mergeSort(vector<int>& res, vector<pair<int,int>>& nums, int l, int r) {
      if(l >= r) return;
      int mid = l + (r - l) / 2;
      mergeSort(res, nums, l, mid);
      mergeSort(res, nums, mid + 1, r);
      merge(res, nums, l, mid, r);
    }

    //* Main function: pair nums with indices, sort and count greater elements
    vector<int> countGreater(vector<int>& nums) {
      vector<pair<int, int>> PairNums(nums.size());
      for(int i = 0; i < nums.size(); i++) PairNums[i] = {nums[i], i};  //* Store value and original index

      vector<int> res(nums.size());
      mergeSort(res, PairNums, 0, nums.size() - 1);
      return res;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = Solution().countGreater(nums);
    cout << "[";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        if(i + 1 < res.size()) cout << ",";
    }
    cout << "]\n";
  }
    return 0;
}