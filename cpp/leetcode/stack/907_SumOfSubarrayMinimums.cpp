#include <bits/stdc++.h>
#define mod (int)(1e9 + 7)

using namespace std; 

/** Sum of Subarray Minimums
 * ? Computes sum of minimums for all possible subarrays
 * ! Uses stack to find previous/next smaller elements, calculates contribution per element
 * ! Time: O(n), Space: O(n) for stacks and result arrays
 */

class Solution {
  public:
    //* Finds next smaller element index from right (or n if none)
    vector<int> NextSmallerElement(vector<int>& nums) {
      vector<int> res(nums.size()) ;
      stack<int> st;
      for(int i = nums.size() - 1; i >= 0; i--) {
        while(!st.empty() && nums[i] <= nums[st.top()]) st.pop();
        res[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
      }
      return res;      
    }

    //* Finds previous smaller element index from left (or -1 if none)
    vector<int> PrevSmallerElement(vector<int>& nums) {
      vector<int> res(nums.size()) ;
      stack<int> st;
      for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[i] < nums[st.top()]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return res;      
    }

    //* Main: compute PSE/NSE, sum (arr[i] * left_subarrays * right_subarrays) % mod
    int sumSubarrayMins(vector<int>& arr) {
      vector<int> NSE = NextSmallerElement(arr);
      vector<int> PSE = PrevSmallerElement(arr);
      long long sum = 0;

      for(int i = 0; i < arr.size(); i++) {
        long long left = i - PSE[i];  //* Subarrays where i is min from left
        long long right = NSE[i] - i;  //* Subarrays where i is min from right
        sum = (sum + (arr[i] * left * right) % mod) % mod;
      }
      return sum;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << Solution().sumSubarrayMins(arr) << endl;
  }
    return 0;
}