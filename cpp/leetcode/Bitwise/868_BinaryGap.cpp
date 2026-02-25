#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: String-based scan
   * ? Logic: Convert `n` to a fixed-width binary string and scan indices of '1' to compute distances.
   * ! Time Complexity: O(b) where b is number of bits (<=32 for 32-bit int).
   * ! Space Complexity: O(b) for the string buffer.
   * * Pros: Straightforward to reason about; good for clarity or arbitrary-width integers.
   * * Cons: Allocates extra buffer; unnecessary for fixed-width ints.
  */
   // Example implementation (commented):
  // int binaryGap(int n) {
  //   string s = bitset<32>(n).to_string();
  //   int last = -1, ans = 0;
  //   for (int i = 0; i < 32; i++) {
  //     if (s[i] == '1') {
  //       if (last != -1) ans = max(ans, i - last);
  //       last = i;
  //     }
  //   }
  //   return ans;
  // }

  /** Approach 2: Bitwise scan (preferred)
   * ? Logic: Iterate bits with right shifts; track index of last seen '1' and update max gap when a new '1' appears.
   * ! Time Complexity: O(b) (scan up to b bits), Space Complexity: O(1).
   * * Pros: Constant space, minimal overhead; ideal for fixed-size integers.
  */
   int binaryGap(int n) {
    int last = -1, ans = 0, i = 0;  // last: index of previous '1', ans: max gap, i: current bit index
    // Scan from least-significant bit upwards
    while (n > 0) {
      if (n & 1) {                   // current bit is 1
        if (last != -1) ans = max(ans, i - last);  // update gap if previous '1' exists
        last = i;                    // record index of this '1'
      }
      n >>= 1;                       // shift to next bit
      i++;                           // advance position
    }
    return ans;                      // maximum distance between consecutive '1's
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << Solution().binaryGap(n) << endl;
  }

  return 0;
}