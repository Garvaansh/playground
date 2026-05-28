#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    pair<int, int> MiniMax(vector<int> arr){
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i : arr) {
          mini = min(mini, i);
          maxi = max(maxi, i);
        } 
      
        return {mini, maxi};
    }

    bool possible(vector<int> arr, int day, int m, int k){
      int count = 0, bouquet = 0;
      int n = arr.size();
      for(int i = 0; i < n; i++){
        if(arr[i] <= day) count++;
        else {
          bouquet += (count / k);
          count = 0;
        }
      }
      bouquet += (count / k);
      return bouquet >= m;
    }

  // Brute force --> 
    // int minDays(vector<int>& bloomDay, int m, int k) {
    //   pair<int, int> miniMax = MiniMax(bloomDay);
    //   int low = miniMax.first, high = miniMax.second;

    //   if((long long)(m*k) > bloomDay.size()) return -1;
    //   for(int i = low; i <= high; i++){
    //     if(possible(bloomDay, i, m, k))
    //       return i;
    //   }
    //   return -1;
    // }

  // -------------------------------------------------------------

  // Optimal Approach --> 
    int minDays(vector<int>& bloomDay, int m, int k) {
      pair<int, int> miniMax = MiniMax(bloomDay);
      int low = miniMax.first, high = miniMax.second;

      if((long long)(m*k) > bloomDay.size()) return -1;
      while(low <= high) {
        int mid = (low + high) / 2;
        if(possible(bloomDay, mid, m, k)) high = mid - 1;
        else low = mid + 1;
      }
      return low;
    }
};

int main(){
  int t, n;
  int m, k;
  cin >> t;

  Solution sol;
  while(t--){
    cin >> n >> m >> k;;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
      cin >> nums[i];
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.minDays(nums, m, k) << endl;  
  }
  return 0;
}