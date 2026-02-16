#include <bits/stdc++.h>
using namespace std; 

class Solution {
  public:
    vector<int> NextSmallerElement(vector<int>& nums) {
      vector<int> res(nums.size()) ;
      stack<int> st;
      for(int i = nums.size() - 1; i >= 0; i--) {
        while(!st.empty() && nums[i] <= st.top()) st.pop();
        res[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
      }
      return res;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> res = Solution().NextSmallerElement(nums);
    cout << "[";
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
        if(i + 1 < res.size()) cout << ",";
    }
    cout << "]\n";
  }
    return 0;
}