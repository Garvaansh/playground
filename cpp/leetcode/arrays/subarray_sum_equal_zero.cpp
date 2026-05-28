#include  <bits/stdc++.h>
using namespace std; 

class Solution{
public:
  int maxSubArrayLength(vector<int>& nums) {
    int maxLen = 0, len = 0, sum = 0;
    unordered_map<int, int> freq = {{0, -1}};
    for(int i = 0; i < nums.size(); i++){
      sum += nums[i];
      if(freq.find(sum) != freq.end()){
        len = i - freq[sum];
        maxLen = max(maxLen, len);
      }
      else{
        freq[sum] = i;
      }
    }
    return maxLen;
  }
};


int main()
{
  int t, n;
  cin >> t;
  int i = 1;

  Solution sol;
  
  while(t--){
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }

    cout << "Test case " << i << ": " << sol.maxSubArrayLength(nums) << endl;
  }

    return 0;
}