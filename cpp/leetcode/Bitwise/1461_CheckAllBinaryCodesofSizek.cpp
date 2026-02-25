#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    unordered_set<string> seen;

    if(s.length() <(1 << k)) return false;
    for (int i = 0; i <= s.length() - k; i++) {
      seen.insert(s.substr(i, k));
    }
    return seen.size() == (1 << k);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int k;
    cin >> s >> k;
    bool res = Solution().hasAllCodes(s.substr(1, s.length() - 2), k);
    cout << (res ? "true" : "false") << endl;
  }

  return 0;
}