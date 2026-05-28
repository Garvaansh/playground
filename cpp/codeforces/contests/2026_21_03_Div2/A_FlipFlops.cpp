#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
 public:
  ll solve(ll& n, ll& c, ll& k, vector<ll>& a) {
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
      if (a[i] <= c) {
        ll boost = min(k, c - a[i]);
        k -= boost;
        c += a[i] + boost;
      }
    }
    return c;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  Solution sol;
  while (t--) {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cout << sol.solve(n, c, k, a) << "\n";
  }

  return 0;
}