#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void reverse(vector<char>& s, int i) {
    int n = s.size();
    if (i == (n / 2)) return;

    swap(s[i], s[n - i - 1]);
    reverse(s, i + 1);
  }

  void reverseString(vector<char>& s) { reverse(s, 0); }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }

    sol.reverseString(s);

    cout << "[";
    for (int i = 0; i < n; ++i) {
    cout << s[i] << ((i < s.size() - 1) ? "," : "");
    }
    cout << "]" << "\n";
  }


  return 0;
}