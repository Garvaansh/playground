#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      vector<int> presum(n+1, 0);
      for(int i = 1; i <= n; i++)
        presum[i] = presum[i-1] + nums[i-1];
      for(int i = 1; i <= n; i++){
        if(presum[i - 1] == presum[n] - presum[i])
          return i - 1;
        }
    return -1;
  }
};

int main(){

  int t, n, i = 1;
  cin >> t;

  Solution sol;

  while(t--){
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }

    cout << "Test case " << i++ << ": " << sol.pivotIndex(nums) << endl;
  }
  return 0;
}