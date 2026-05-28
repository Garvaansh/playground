#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int startPos(vector<int>& nums, int target){
      int left = 0, right = nums.size() - 1, ans = -1;
      while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target){
          ans = mid;
          right = mid - 1;
        }else if(nums[mid] < target){
          left = mid + 1;
        }else{
          right = mid - 1;
        }
      }
      return ans;
    }

    int endPos(vector<int>& nums, int target){
      int left = 0, right = nums.size() - 1, ans = -1;
      while(left <= right){
        int mid = (left + right)/2;
        if(nums[mid] == target){
          ans = mid;
          left = mid + 1;
        }else if(nums[mid] < target){
          left = mid + 1;
        }else{
          right = mid - 1;
        }
      }
      return ans;
    }

    int CountOccurances(vector<int> &nums, int target){
      int a = startPos(nums, target); 
      int b = endPos(nums, target);
      return b - a + 1;
    }
};

int main() {
  int t, n, tar;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n >> tar;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }

    static int i = 1;
    int ans = sol.CountOccurances(nums, tar);
    cout << "Test case " << i++ << ": " << ans << endl;
  }
  return 0;
}