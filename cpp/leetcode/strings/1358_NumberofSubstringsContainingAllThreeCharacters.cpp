#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int cnt = 0;
    int l = 0, r = 0;
    vector<int> freq(3, 0);  // freq[0] for 'a', freq[1] for 'b', freq[2] for 'c'

    while (r < s.size()) {
      freq[s[r] - 'a']++;

      while (freq[0] && freq[1] && freq[2]) {
        cnt += s.size() - r;  // All substrings starting from l to the end of the string are valid
        freq[s[l] - 'a']--;
        l++;
      }

      r++;
    }

    return cnt;
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  Solution sol;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == '"') s = s.substr(1, s.size() - 2);  // Remove the surrounding quotes
    int result = sol.numberOfSubstrings(s);
    cout << result << "\n";
  }

  return 0;
}