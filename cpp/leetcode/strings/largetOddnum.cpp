#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Helper function to generate the SubString 
  // from 0 - last odd digit.
    string subString(string s, int length) {
      string ans = "";
      for(int i = 0; i < length; i++) {
        ans += s[i];
      }
      return ans;
    }


    string largestOddNumber(string num) {
        for(int i = num.length() - 1; i >= 0; i--) {
            if((num[i] - '0') % 2 != 0) {
                return subString(num, i + 1);
            }
        }
        return "";
    }
};

int main() {
  int t;
  cin >> t;
  string s;

  Solution sol;
  while(t--){
    cin >> s;
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.largestOddNumber(s) << endl;
  }
  return 0;
}