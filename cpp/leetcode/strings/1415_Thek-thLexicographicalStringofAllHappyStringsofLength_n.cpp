#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /**       choices
   *        a      b      c
   *      /  \    /  \    /  \
   *     b    c  a    c  a    b
   *   / \   / \ / \  / \ / \  / \
   *  ...
   *
   * A happy string cannot repeat adjacent characters.
   *
   * So after choosing a character we only have 2 choices left.
   *
   * Total happy strings of length n:
   *   3 * 2^(n-1)
   *
   * Lexicographically the strings form partitions:
   *
   * n = 3 example:
   *
   * 1-4   → a**
   * 5-8   → b**
   * 9-12  → c**
   *
   * Each partition size = 2^(n-1)
   *
   * Inside "a":
   *
   * 1-2 → ab*
   * 3-4 → ac*
   *
   * Inside "ab":
   *
   * 1 → aba
   * 2 → abc
   *
   * So the idea is:
   * Instead of generating all strings,
   * jump directly to the correct partition using k.
   */

  string getHappyString(int n, int k) {
    int total_happy = 3 * (1 << (n - 1));  // total possible happy strings
    if (k > total_happy) return "";

    k--;  // convert to 0-indexed for easier block math

    string res = "";
    char prev = '#';  // previous character to enforce happy condition

    for (int i = 0; i < n; i++) {
      // size of each partition at this depth
      // remaining length = n-i-1
      int partition_size = 1 << (n - i - 1);

      for (char c : {'a', 'b', 'c'}) {
        // skip same character as previous (happy constraint)
        if (c == prev) continue;

        if (k < partition_size) {
          // k lies inside this character's partition
          res += c;
          prev = c;
          break;
        }

        // otherwise skip this partition
        k -= partition_size;
      }
    }

    return res;
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
    int n, k;
    cin >> n;
    cin >> k;
    string result;
    result = sol.getHappyString(n, k);
    cout << result << "\n";
  }

  return 0;
}