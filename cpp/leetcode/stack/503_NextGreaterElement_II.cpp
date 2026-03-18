#include <bits/stdc++.h>
using namespace std; 

/** Next Greater Element II
 * ? Finds next greater element for each num in circular array
 * ! Uses stack, iterates 2*n to handle circularity, pops smaller elements
 * ! Time: O(n), Space: O(n) for stack and result
 */

class Solution {
public:
    //* Main function: simulate circular by 2*n iteration, build next greater array
    vector<int> nextGreaterElement(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size());
        //* Iterate 2*n from right to left for circular effect
        for(int i = 2*nums.size() -1; i >= 0; i--) {
            //* Pop elements <= current to find next greater
            while(!st.empty() && nums[i % nums.size()] >= st.top()) st.pop();
            //* Set result: stack top if exists, else -1
            res[i % nums.size()] = (st.empty()) ? -1 : st.top();
            //* Push current element onto stack
            st.push(nums[i % nums.size()]);
        }
        return res;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    vector<int> nums1;
    int n1;
    cin >> n1;
    for(int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        nums1.push_back(x);
    }
    vector<int> res = Solution().nextGreaterElement(nums1);
    string ans = "[";
    for(int i : res) ans += to_string(i) + ",";
    if(ans.size() > 1) ans.pop_back();
    ans += "]";
    cout << ans << endl;
  }
    return 0;
}