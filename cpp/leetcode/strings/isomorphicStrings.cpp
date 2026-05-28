#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> mp1, mp2;

      for(int i = 0; i < s.length(); i++){
        char ch1 = s[i], ch2 = t[i];

        if(mp1.find(ch1) != mp1.end()){
          if(mp1[ch1] != ch2) return false;
        } else {
          mp1[ch1] = ch2;
        }

        if(mp2.find(ch2) != mp2.end()){
          if(mp2[ch2] != ch1) return false;
        } else {
          mp2[ch2] = ch1;
        }
      }
      return true;
    }
};

int main() {
  int t, i = 1;
  cin >> t;
  string s, k;
  Solution sol;
  while(t--){
    cin >> s >> k;
    string ans = sol.isIsomorphic(s, k) ? "true" : "false";
    cout << "Test case " << i++ << ": " << ans << endl;
  }

    return 0;
}