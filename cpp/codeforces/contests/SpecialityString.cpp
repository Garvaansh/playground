// Problem link: https://codeforces.com/contest/2200/problem/C

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isSpecialString(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (!st.empty() && st.top() == s[i]) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    return st.empty();
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << ((n < 2) ? "NO" : (Solution().isSpecialString(s) ? "YES" : "NO")) << endl;
  }
  return 0;
}