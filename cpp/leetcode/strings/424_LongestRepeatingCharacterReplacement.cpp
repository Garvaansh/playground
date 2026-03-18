#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Brute force..
   * Generate all subarrays and check if a different element is found
   */
  // int characterReplacement(string s, int k) {
  //   int maxLen = 0;
  //   for (int i = 0; i < s.size(); i++) {
  //     vector<char> seen(26, 0);
  //     for (int j = i; j < s.size(); j++) {
  //       seen[s[j] - 'A']++;
  //       int maxFreq = *max_element(seen.begin(), seen.end());
  //       if ((j - i + 1) - maxFreq > k) {
  //         break;
  //       }
  //       maxLen = max(maxLen, j - i + 1);
  //     }
  //   }
  //   return maxLen;
  // }

  /** Approach 2: Sliding Window
   * Intuition: Use a sliding window to maintain a valid substring where the number of characters
   * that need to be replaced (window size - max frequency) is at most k.
   * Expand the right pointer and update counts, and if the window becomes invalid,
   * move the left pointer until it becomes valid again.
   * Track the maximum window size during this process.
   * TC: O(n)
   * SC: O(26) since we only have 26 uppercase letters to count.
   */
  // int characterReplacement(string s, int k) {
  //   int left = 0, right = 0, maxFreq = 0, maxLen = 0;
  //   vector<int> count(26, 0);
  //   while (right < s.size()) {
  //     count[s[right] - 'A']++;
  //     maxFreq = max(maxFreq, count[s[right] - 'A']);
  //     while ((right - left + 1) - maxFreq > k) {
  //       count[s[left] - 'A']--;
  //       left++;
  //     }
  //     maxLen = max(maxLen, right - left + 1);
  //     right++;
  //   }
  //   return maxLen;
  // }

  /** Approach 3: Sliding Window (Optimized)
   * Instead of shrinking down the window immediately till k is valid,
   * we keep it as is, and continue iterating, and only when we find a window that is invalid,
   * we shrink it down by one character. 
   * TC: O(n) — each character is processed at most twice (once when expanding and once when shrinking).
   * SC: O(26) — for the count array of uppercase letters.
   */
  int characterReplacement(string s, int k) {
    int left = 0, right = 0, maxFreq = 0, maxLen = 0;
    vector<int> count(26, 0);
    while (right < s.size()) {
      count[s[right] - 'A']++;
      maxFreq = max(maxFreq, count[s[right] - 'A']);
      if ((right - left + 1) - maxFreq > k) {
        count[s[left] - 'A']--;
        left++;
      }
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
    return maxLen;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int k;
    cin >> s >> k;
    // Remove quotes if present
    if (s[0] == '"') s = s.substr(1, s.size() - 2);
    cout << Solution().characterReplacement(s, k) << endl;
  }

  return 0;
}