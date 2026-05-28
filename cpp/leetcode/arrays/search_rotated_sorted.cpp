#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
  // Function to find the pivot index. 
    int findPivot(vector<int> & nums){
      int i = 0, j = nums.size() - 1;
      while(i <= j){
        int mid = i + (j - i)/2;
        if(nums[mid] > nums[nums.size() - 1]) i = mid + 1;
        else if(nums[mid] < nums[nums.size() - 1]) j = mid - 1;
        else break;
      }
      return i;
    }

    // performing binary search on the rotated array
    int search(vector<int>& nums, int target){
      int pivot = findPivot(nums);
      int left = 0, right = nums.size() - 1;
      while( left <= right){
        // Finding mid as usual assuming this to be a sorted array
        int mid = (left + right)/2;
        // Finds the actual index of the mid element in original array
        int realMid = (mid + pivot) % nums.size();
        if(nums[realMid] == target) return realMid;
        else if(nums[realMid] < target) left = mid + 1;
        else right = mid - 1;
      }
      return -1;
    }
};

int main(){
  int t, n, target;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    static int i = 1;
    cout << "Test Case " << i++ << ": " <<  sol.search(nums, target) << endl;
  }
  return 0;
}
