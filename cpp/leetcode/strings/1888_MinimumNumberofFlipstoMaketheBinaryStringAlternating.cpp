#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Sliding Window
   * TC: O(n)
   * SC: O(2n) 's+s'
   */
  // int minFlips(string s) {
  //   string s = s + s;
  //   int n = s.size();

  //   int l = 0, r = 0;
  //   int diff1 = 0, diff2 = 0;
  //   int minCnt = INT_MAX;

  //   while (r < s.size()) {
  //     char p1 = (r % 2) ? '1' : '0';  // pattern 010101...
  //     char p2 = (r % 2) ? '0' : '1';  // pattern 101010...

  //     if (s[r] != p1) diff1++;
  //     if (s[r] != p2) diff2++;

  //     if (r - l + 1 > n) {
  //       char lp1 = (l % 2) ? '1' : '0';
  //       char lp2 = (l % 2) ? '0' : '1';

  //       if (s[l] != lp1) diff1--;
  //       if (s[l] != lp2) diff2--;

  //       l++;
  //     }

  //     if (r - l + 1 == n) {
  //       minCnt = min(minCnt, min(diff1, diff2));
  //     }

  //     r++;
  //   }

  //   return minCnt;
  // }

  /** Approach 2: Sliding Window (Space Optimized)
   *  Idea:
   *  - Rotating the string is equivalent to checking every length-n substring
   *    in (s + s). Instead of actually building s+s, we simulate it using % n.
   *
   *  - For any binary string, there are only two valid alternating patterns:
   *        P1: 010101...
   *        P2: 101010...
   *
   *  - For each window (which represents one rotation), we count mismatches
   *    against both patterns using diff1 and diff2.
   *
   *  - The sliding window ensures we maintain mismatch counts in O(1) time
   *    when a character enters or leaves the window.
   *
   *  TC: O(n)   (window slides across 2n positions)
   *  SC: O(1)   (no extra string allocation)
   */
  int minFlips(string s) {
    int n = s.size();
    int l = 0, r = 0;
    int diff1 = 0, diff2 = 0;
    int minCnt = INT_MAX;

    while (r < 2 * n) {
      char p1 = (r % 2) ? '1' : '0';  // pattern 010101...
      char p2 = (r % 2) ? '0' : '1';  // pattern 101010...

      if (s[r % n] != p1) diff1++;
      if (s[r % n] != p2) diff2++;

      if (r - l + 1 > n) {
        char lp1 = (l % 2) ? '1' : '0';
        char lp2 = (l % 2) ? '0' : '1';

        if (s[l % n] != lp1) diff1--;
        if (s[l % n] != lp2) diff2--;

        l++;
      }

      if (r - l + 1 == n) {
        minCnt = min(minCnt, min(diff1, diff2));
      }

      r++;
    }

    return minCnt;
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  Solution sol;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == '"') s = s.substr(1, s.size() - 2);  // Remove the surrounding quotes
    int result = sol.minFlips(s);
    cout << result << "\n";
  }
  return 0;
}