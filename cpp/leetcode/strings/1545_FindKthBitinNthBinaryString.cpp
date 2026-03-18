#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Iterative + String build
   * Since n <= 20, we can build the string iteratively and return the k-1 th character
   * TC: O(2^n) to build the string and O(1) to return the k-1 th character
   * SC: O(2^n) to store the string
   */
  // string build(int n) {
  //   if (n == 1) return "0";

  //   string prev = build(n - 1);
  //   string rev = prev;
  //   reverse(rev.begin(), rev.end());

  //   for (char& c : rev)
  //     c = (c == '0') ? '1' : '0';

  //   return prev + "1" + rev;
  // }

  // char findKthBit(int n, int k) {
  //   string s = build(n);
  //   return s[k - 1];
  // }

  /** Approach 2: Recursive + Math (Optimized)
   * Same logic as approach 3 but implemented recursively
   * TC: O(n) to find the mid point and mirror position and O(1) to return the character
   * SC: O(n) to store the recursive stack and O(1) to store the character
   */

  // char findKthBit(int n, int k) {
  //   // Base case: When n = 1, the binary string is "0"
  //   if (n == 1) return '0';

  //   // Find the length of the current string Sn, which is 2^n - 1
  //   int length = (1 << n) - 1;

  //   // Find the middle position
  //   int mid = length / 2 + 1;

  //   // If k is the middle position, return '1'
  //   if (k == mid) return '1';

  //   // If k is in the first half, find the bit in Sn-1
  //   if (k < mid) return findKthBit(n - 1, k);

  //   // If k is in the second half, find the bit in Sn-1 and invert it
  //   return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
  // }

  /** Approach 3: Iterative + Math (Optimized)
   * We know the string build is 2^n - 1
   * We can find the mid point of the string and check if k is at mid point
   * If k is at mid point, then return 1 at mid point
   * If k is in right half, then we can find the mirror position of k in left half
   * and check if it is 0 or 1
   *
   * TC: O(n) to find the mid point and mirror position and O(1) to return the character
   * SC: O(1) to store the character
   */
  char findKthBit(int n, int k) {
    bool flip = false;

    while (n > 1) {
      int len = (1 << n) - 1;
      int mid = len / 2 + 1;

      if (k == mid) return flip ? '0' : '1';

      if (k > mid) {
        k = len - k + 1;  // mirror
        flip = !flip;     // because right half is inverted
      }

      n--;
    }

    // base case S1 = "0"
    return flip ? '1' : '0';
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    cin >> k;
    cout << Solution().findKthBit(n, k) << endl;
  }

  return 0;
}