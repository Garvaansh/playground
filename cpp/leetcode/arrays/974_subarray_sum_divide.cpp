#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> res = {{0,1}};
        int presum = 0, count = 0;
        for(int i = 0; i < n; i++){
          presum += nums[i];
          int rem = presum % k;
          if(rem < 0) rem += k;
          if(res.find(rem) != res.end())
            count += res[rem];
          res[rem]++;
          } 
      return count;
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

    cout << sol.subarraysDivByK(nums, k) << endl;
  }
  return 0;
}