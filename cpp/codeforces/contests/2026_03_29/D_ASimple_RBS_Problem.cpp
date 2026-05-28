#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countBlocks(string& s) {
    int bal = 0, cnt = 0;
    for (char c : s) {
      if (c == '(')
        bal++;
      else
        bal--;

      if (bal == 0) cnt++;
    }
    return cnt;
  }

  bool isRBS(string& s, string& t) { 
    return countBlocks(s) == countBlocks(t); 
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    cout << (sol.isRBS(s, t) ? "YES" : "NO") << endl;
  }

  return 0;
}