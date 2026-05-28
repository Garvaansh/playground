#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int singleNonDuplicate(vector<int>& nums){
      int l = 0, r = nums.size() - 1, n = nums.size();
    //Edge cases:
      if (n == 1) return nums[0];
      if (nums[0] != nums[1]) return nums[0];
      if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

      while (l <= r){
        int m = l + (r - l) / 2;
        if(m > 0 && nums[m - 1] == nums[m]) {
          if((r - m) % 2 != 0) l = m + 1;
          else r = m - 2;
        }
        else if(m+1 < n && nums[m + 1] == nums[m]) {
          if((r - m) % 2 == 0) l = m + 2;
          else r = m - 1;
        }
        else return nums[m];
      }
      return -1;
    }
};

int main(){
  int t, n;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.singleNonDuplicate(nums) << endl;
  }
  return 0;
}