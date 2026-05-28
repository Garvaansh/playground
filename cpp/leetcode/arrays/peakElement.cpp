#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findPeakElement(vector<int>& nums) {
      int l = 1, r = nums.size() - 2, n = nums.size();
      // Edge cases
      if(n == 1) return 0;
      if(nums[0] > nums[1]) return 0;
      if(nums[n-1] > nums[n-2]) return n-1;

      // Finding peak in rest of array
      while(l <= r){
        int m = l + (r - l) / 2;
        if(nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) return m;
        else if(nums[m - 1] < nums[m]) l = m + 1;
        else r = m - 1; 
      }
      return -1;
    } 
};

int main() {
  int t, n;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.findPeakElement(nums) << endl;
  }
  return 0;
}