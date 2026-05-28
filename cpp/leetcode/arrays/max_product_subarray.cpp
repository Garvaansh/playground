#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxProduct(vector<int>& nums){
       // Brute Force -->
        // int maxProd = INT_MIN;
        // for(int i = 0; i < nums.size(); i++){
        //   int Prod = 1;
        //   for(int j = i; j < nums.size(); j++){
        //     Prod *= nums[j];
        //     maxProd = max(maxProd, Prod);
        //   }
        // }
        // return maxProd;

  // ------------------------------------------------------ //
        
        // Optimal Approach -->
        int maxProd = INT_MIN, Prefix = 1, Suffix = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++ ) {
          if(Prefix == 0) Prefix = 1;
          if(Suffix == 0) Suffix = 1;
          
          Prefix *= nums[i];
          Suffix *= nums[n - i - 1];

          maxProd = max(maxProd, max(Prefix, Suffix));
        } 
        return maxProd;
    }
};

int main(){

  int t, n;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }

    static int counter = 1;
    int ans = sol.maxProduct(nums);
    cout << "Test case " << counter++ << ": " << ans << endl;
  }
  return 0;
}