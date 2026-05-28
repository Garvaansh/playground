#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> one_cnt(string s) {
  int n = s.size();

  // ---------- MAXIMUM ----------
  string mx = s;
  bool changed = true;

  while (changed) {
    changed = false;

    for (int i = 1; i < n - 1; i++) {
      if (mx[i - 1] == '1' && mx[i + 1] == '1' && mx[i] == '0') {
        mx[i] = '1';
        changed = true;
      }
    }
  }

  int maxOnes = count(mx.begin(), mx.end(), '1');

  // ---------- MINIMUM ----------
  string mn = s;
  changed = true;

  while (changed) {
    changed = false;

    for (int i = 1; i < n - 1; i++) {
      if (mn[i - 1] == '1' && mn[i + 1] == '1' && mn[i] == '1') {
        mn[i] = '0';
        changed = true;
      }
    }
  }

  int minOnes = count(mn.begin(), mn.end(), '1');

  return {minOnes, maxOnes};
}

void solve() {
  int n;
  string s;
  cin >> n >> s;
  cout << one_cnt(s).first << " " << one_cnt(s).second << "\n";
}

int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}