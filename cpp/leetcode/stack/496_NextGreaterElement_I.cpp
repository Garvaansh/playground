#include <bits/stdc++.h>
using namespace std; 

/** Next Greater Element I
 * ? Finds next greater element for each num in nums1 using nums2
 * ! Uses stack to precompute next greater elements for nums2, then maps for nums1
 * ! Time: O(n1 + n2), Space: O(n2) for stack and map 
 */

class Solution {
public:
    //* Main function: iterate nums2 to build next greater map, then query for nums1
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;
        //* Last element has no greater, set to -1
        mpp[nums2[nums2.size() - 1]] = -1;
        //* Iterate nums2 from right to left, maintain decreasing stack
        for(int i = nums2.size() - 1; i >= 0; i--) {
            //* Pop elements smaller than current to find next greater
            if(!st.empty() && nums2[i] > st.top()) {
                while(!st.empty() && nums2[i] > st.top()) st.pop();
            }
            //* Map current to stack top (next greater) or -1 if empty
            (!st.empty()) ? mpp[nums2[i]] = st.top() : mpp[nums2[i]] = -1;
            //* Push current element onto stack
            st.push(nums2[i]);
        }

        vector<int> res;
        //* For each in nums1, append mapped next greater value
        for(int i : nums1) {
            if(mpp.find(i) != mpp.end()) res.push_back(mpp[i]);
        }
        return res;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    vector<int> nums1, nums2;
    int n1, n2;
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        nums1.push_back(x);
    }
    for(int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        nums2.push_back(x);
    }
    vector<int> res = Solution().nextGreaterElement(nums1, nums2);
    string ans = "[";
    for(int i : res) ans += to_string(i) + ",";
    if(ans.size() > 1) ans.pop_back();
    ans += "]";
    cout << ans << endl;
  }
    return 0;
}