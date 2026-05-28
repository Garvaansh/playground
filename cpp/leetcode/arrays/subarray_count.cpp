#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int subarraySum(vector<int>& nums, int k){
      unordered_map<int, int> mpp = {{0, 1}}; //sum, count
      int presum = 0, count = 0;

      for(int i = 0; i < nums.size(); i++){
        presum += nums[i];
        int reduce = presum - k;
        if(mpp.find(reduce) != mpp.end()){
          count += mpp[reduce];
        }
        mpp[presum]++;
      }
      return count;
    }
};

int main(){

  int t;
  cin >> t;
  int i = 1;

  Solution sol;
  while(t--){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
      cin >> arr[i];
    }

    int result = sol.subarraySum(arr, k);
    cout << "Test case " << i++ << ": " << result << endl;
  }

  return 0;
}