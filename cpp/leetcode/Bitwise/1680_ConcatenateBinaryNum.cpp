#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
 public:
  /** Approach 1: Calculating digits to right shift at each iteration */
  // int concatenatedBinary(int n) {
  //   ll ans = 0;
  //   for (int i = 1; i <= n; i++) {
  //     int digits = log2(i) + 1;  // number of bits in i
  //     ans = (((ans << digits) | i) % MOD;
  //   }
  //   return (int)ans;
  // }

  /** Approach 2: Computes number of bits required at power of 2 steps */
  int concatenatedBinary(int n) {
    ll ans = 0;
    int shift = 0;  // to keep track of number of bits to shift at each iteration
    for (int i = 1; i <= n; i++) {
      if ((i & (i - 1)) == 0) {  // power of 2
        shift++;
      }
      ans = ((ans << shift) | i) % MOD;
    }
    return (int)ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << Solution().concatenatedBinary(n) << endl;
  }

  return 0;
}