#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<string> splitWords(string& s) {
        vector<string> words;
        string word;
        for (char c : s) {
            if (c != ' ') word += c;
            else if (!word.empty()) {
                words.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) words.push_back(word);
        return words;
    }

    string reverseWords(string s) {
      vector<string> words = splitWords(s);
      int n = words.size() - 1;

      string ans = "";
      for(int i = n; i >= 0; i--){
        ans += words[i];
        if(i != 0) ans += ' '; 
      }
      return ans;
    }
};

int main() {
  string s;
  Solution sol;

  int t;

  cin >> t;
  cin.ignore();
  while(t--){
    getline(cin, s);
    static int i = 1;
    cout << "Test case " << i++ << ": " << sol.reverseWords(s) << endl;
  }
  return 0;
}
