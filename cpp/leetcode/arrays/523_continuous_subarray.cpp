#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_map = {{0,-1}};
        // remainder_map[0] = -1; // Initialize to handle prefix sums divisible by k
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
          sum += nums[i];
          int rem = sum % k;
            if (remainder_map.find(rem) != remainder_map.end()) {
                if (i - remainder_map[rem] >= 2) {
                    return true;
                }
            } else {
                remainder_map[rem] = i;
            }
        }
        return false;
    }
};

int main(){
  int t, n, k;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n >> k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
      cin >> nums[i];

    string ans = (sol.checkSubarraySum(nums, k) ? "true" : "false");
    cout << ans << endl;
  }

  return 0;
}