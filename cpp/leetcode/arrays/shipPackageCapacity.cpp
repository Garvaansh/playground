#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
  /* helper function to find the search space 
    min --> maximum element in the array
    max --> total sum of the array */
  pair<int, int> miniMax(vector<int>& weights) {
    int mini = INT_MIN, maxi = 0;
    for(int i : weights){
      mini = max(mini, i);
      maxi += i;
    }
    return {mini, maxi};
  }

  /* bool function to check possibility 
    params --> array, weight, days  */
    bool possible(vector<int>& weights, int weight, int days) {
      int sum = 0, total_days = 1;
      for(int i : weights){
        if(sum + i > weight) {
          total_days++;
          sum = 0;
        }
        sum += i;
      }
      return total_days <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
      pair<int, int> MiniMax = miniMax(weights);
      int low = MiniMax.first, high = MiniMax.second;
      while(low <= high) {
        int mid = (low + high) / 2;
        if(possible(weights, mid, days)) high = mid - 1;
        else low = mid + 1;
      }
      return low;
    }
};

int main() {
  int t, n, days, i = 1;
  cin >> t;
  Solution sol;

  while(t--) {
    cin >> n >> days;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];
    cout << "Test case " << i++ << ": " << sol.shipWithinDays(weights, days) << endl;
  }

    return 0;
}