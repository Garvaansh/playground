#include <bits/stdc++.h>
using namespace std;

class Solution{
  public: 
    int merge(vector<int> &nums, int low, int mid, int high) {
      vector<int> temp;
      int left = low, right = mid + 1;
      // declaring count to find the pairs
      int count = 0;
      // Using two pointer approach. 
      int j = mid + 1;
      /* checks all the valid pairs. rather than 
        just finding a single pair (if it finds) and 
        adding the rest of element to count. 
        example: 
        [2,3,4]  [1,5]
        here 2 is not a valid pair for 1 but rest (3,4) are.. 
      */
      for(int i = low; i <= mid; i++){
        while(j <= high && nums[i] > 2 * nums[j]) j++;
        count += j - mid - 1;
      }

      //merging and storing the array in temp
      while(left <= mid && right <= high){
        if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
        else temp.push_back(nums[right++]);
    
      }
      
      while(left <= mid) temp.push_back(nums[left++]);
      while(right <= high) temp.push_back(nums[right++]);
      for(int i = low; i <= high; i++) nums[i] = temp[i - low];
    return count;
    }

    int mergeSort(vector<int> &nums, int left, int right) {
      int count = 0;
      if(left >= right) return count;
      int mid = (left + right)/2;
      count += mergeSort(nums, left, mid);
      count += mergeSort(nums, mid + 1, right);
      count += merge(nums, left, mid, right);
      return count;
    }
    int reversePairs(vector<int>& nums) {
  // Brute force -->

      // int n = nums.size(), count = 0;
      // for(int i = 0; i < n - 1; i++){
      //   for(int j = i + 1; j < n; j++){
      //     if(nums[i] > 2*nums[j]) count++;
      //   }
      // }
      // return count;
  // --------------------------------------------------------
  // optimal approach - mergeSort -->

      return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
  int t, n;
  cin >> t;
  Solution sol;
  while(t--){ 
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < n; i++){
    cin >> nums[i];
  }
  static int i = 1;
  int ans = sol.reversePairs(nums);
  cout << "Test case "<< i++ << ": " << ans << endl;
  }
  return 0;
}