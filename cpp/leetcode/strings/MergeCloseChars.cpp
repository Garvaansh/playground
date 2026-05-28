//? Problem Link: https://leetcode.com/problems/merge-close-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string mergeCharacters(string s, int k) {
    bool isMerged = true;
    string temp = s;

    while (isMerged) {
      isMerged = false;
      unordered_map<char, int> idx;

      for (int i = 0; i < temp.length(); i++) {
        if (idx.find(temp[i]) != idx.end()) {
          if (i - idx[temp[i]] <= k) {
            temp.erase(i, 1);
            isMerged = true;
            break;
          } else {
            idx[temp[i]] = i;
          }
        } else {
          idx[temp[i]] = i;
        }
      }
    }
    return temp;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int k;
    cin >> s >> k;
    cout << Solution().mergeCharacters(s.substr(1, s.length() - 2), k) << endl;
  }

  return 0;
}