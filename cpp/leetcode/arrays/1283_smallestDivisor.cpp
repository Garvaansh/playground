#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    pair<int, int> miniMax(vector<int>& nums){
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i : nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return {mini, maxi};
    }
    
    bool Possible(vector<int>& nums, int divisor, int threshold){
        long long sum = 0;
        for(int i : nums){
            sum += ceil((long long)i / divisor);
        }
        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        pair<int, int> MiniMax = miniMax(nums);
        int i = 1, j = MiniMax.second;
        while(i <= j){
          int mid = (i + j) / 2;
          if(Possible(nums, mid, threshold)) j = mid - 1;
          else i = mid + 1;
        }    
        return i;
    }
};

int main() {
  int t, n, threshold;
  cin >> t;
  Solution sol;
  while(t--){ 
    cin >> n >> threshold;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
      cin >> nums[i];
    }
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.smallestDivisor(nums, threshold) << endl;
  }

    return 0;
}