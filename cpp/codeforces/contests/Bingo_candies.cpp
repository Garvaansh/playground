#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(int n, vector<vector<int>>& candies) {
  unordered_map<int, int> freq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      freq[candies[i][j]]++;
    }
  }

  for (auto& [candy, count] : freq) {
    if (count > n * (n - 1)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> candies(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> candies[i][j];
      }
    }
    solve(n, candies);
  }

  return 0;
}