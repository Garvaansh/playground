#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  ll solve(vector<ll>& arr) { return; }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  Solution sol;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cout << sol.solve(arr) << "\n";
  }

  return 0;
}