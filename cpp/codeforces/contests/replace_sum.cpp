//! Incorrect solution

#include <bits/stdc++.h>
using namespace std;

vector<int> best_sum(int n, vector<int>& a, vector<int>& b) {
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = max(a[i], b[i]);
  }

  vector<int> d(n);
  for (int i = n - 1; i >= 0; i--) {
    d[i] = (i == n - 1) ? c[i] : (max(c[i], d[i + 1]));
  }

  vector<int> prefixSum(n, 0);
  for (int i = 0; i < n; i++) {
    prefixSum[i] = (i == 0) ? d[i] : (prefixSum[i - 1] + d[i]);
  }
  return prefixSum;
}

int replaceSum(int n, int l, int r, vector<int>& prefixSum) {
  int result = 0;
  for (int i = l - 1; i < r; i++) {
    result += prefixSum[i];
  }
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    vector<int> prefixSum = best_sum(n, a, b);

    while (q--) {
      cin >> l >> r;
      cout << (prefixSum[r - 1] - ((l > 1) ? prefixSum[l - 2] : 0)) << " ";
    }
    cout << "\n";
  }

  return 0;
}