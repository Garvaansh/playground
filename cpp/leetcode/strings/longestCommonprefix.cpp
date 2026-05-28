#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string ans = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                    return ans;
            }
            ans += strs[0][i];;
        }
        return ans;
    }
};

int main() {
    int t, n;
    cin >> t;

    Solution sol;
    
    while(t--) {
      cin >> n;
      vector<string> strs(n);
      for(int i = 0; i < n; i++) {
        cin >> strs[i];
      }
      static int i = 1;
      cout << "Test case " << i++ << ": " << sol.longestCommonPrefix(strs) << endl;
    }

  return 0;
}