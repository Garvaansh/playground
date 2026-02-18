#include <bits/stdc++.h>
using namespace std; 

using ll = long long;

/** Sum of Subarray Ranges
 * ? Computes sum of (max - min) for all possible subarrays
 * ! Uses stack for previous/next greater/smaller elements, calculates per-element contributions
 * ! Time: O(4n) amortized (4 stack passes, each O(n)), Space: O(n)
 */

class Solution {
public:
    //* Finds next greater element index from right (or n if none)
    vector<int> NextGreaterElement(vector<int>& nums) {
      vector<int> res(nums.size());
      stack<int> st;
      for(int i = nums.size() - 1; i >= 0; i--) {
        while(!st.empty() && nums[i] >= nums[st.top()]) st.pop();
        res[i] = st.empty() ? nums.size() : st.top();
        st.push(i);
      }
      return res;
    }

    //* Finds previous greater element index from left (or -1 if none)
    vector<int> PrevGreaterElement(vector<int>& nums) {
      vector<int> res(nums.size());
      stack<int> st;
      for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[i] > nums[st.top()]) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return res;
    }

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

    //* Computes sum of max contributions: nums[i] * left_subarrays * right_subarrays
    ll SumMax(vector<int>& nums) {
      vector<int> NGE  =  NextGreaterElement(nums);
      vector<int> PGE = PrevGreaterElement(nums); 
      ll sum = 0;
      for(int i = 0; i < nums.size(); i++) {
        ll left = i - PGE[i];
        ll right = NGE[i] - i;
        sum += (nums[i] * left * right);
      }
      return sum;
    }

    //* Computes sum of min contributions: nums[i] * left_subarrays * right_subarrays
    ll SumMin(vector<int>& nums) {
      vector<int> NSE  =  NextSmallerElement(nums);
      vector<int> PSE = PrevSmallerElement(nums); 
      ll sum = 0;
      for(int i = 0; i < nums.size(); i++) {
        ll left = i - PSE[i];
        ll right = NSE[i] - i;
        sum += (nums[i] * left * right);
      }
      return sum;
    }

    //* Main: return SumMax - SumMin for total range sum
    long long subArrayRanges(vector<int>& nums) {
        ll sumMax = SumMax(nums);
        ll sumMin = SumMin(nums);
        return sumMax - sumMin;
        
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
    cout << Solution().subArrayRanges(arr) << endl;
  }
    return 0;
}