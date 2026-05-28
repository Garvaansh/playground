// Problem Link: https://codeforces.com/contest/2200/problem/E

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // precompute a sieve for SPF of range 1 million. (according to constraint)
  vector<int> spf_sieve(int n) {
    vector<int> spf(n + 1);
    for (int i = 1; i <= n; i++) {
      spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
      if (spf[i] == i) {  // i is prime
        for (int j = i * i; j <= n; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
    return spf;
  }

  bool whoWins(vector<int>& a, vector<int>& spf) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      if (a[i] > a[i + 1]) {
        while (a[i] % spf[a[i]] == 0) {
          a[i] /= spf[a[i]];
        }
        return false;
      }
    }
    return true;
  }
};

int main() {
  int t;
  cin >> t;
  int maxi = 1000000;
  vector<int> spf = Solution().spf_sieve(maxi);
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    cout << (Solution().whoWins(a, spf) ? "Bob\n" : "Alice\n") << endl;
  }
  return 0;
}