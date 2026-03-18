#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mpp;
    int left = 0, right = 0, Maxlen = 0;
    while (right < s.length()) {
      if (mpp.find(s[right]) != mpp.end()) left = max(left, mpp[s[right]] + 1);
      mpp[s[right]] = right;
      Maxlen = max(Maxlen, right - left + 1);
      right++;
    }
    return Maxlen;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << Solution().lengthOfLongestSubstring(s.substr(1, s.length() - 2)) << endl;
  }

  return 0;
}