#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution{
  public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
      int n = nums.size();
      unordered_set<int> s;
      int total = n*(n+1)/2;
      int sum = 0, dup = 0;
      vector<int> ans;
      for(int i : nums){
        if(s.find(i) != s.end()) dup = i;
        s.insert(i);
        sum += i;
      }
      return {dup, total - (sum - dup)};
    }
};

int main() {
  int t, n;
  cin >> t;
  while(t--){
  cin >> n;

  vector<int> nums(n);
  for(int i = 0; i < n; i++) cin >> nums[i];

  Solution sol;
  static int i = 1;
  vector<int> ans = sol.findMissingRepeatingNumbers(nums);
  cout << "Test case "<< i++ << ": " << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}