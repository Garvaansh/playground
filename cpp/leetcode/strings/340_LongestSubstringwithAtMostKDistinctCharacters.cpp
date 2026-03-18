#include <bits/stdc++.h>
using namespace std;

/**
 * find the length of the longest substring with at most k distinct characters
 * @param k the maximum number of distinct characters allowed in the substring
 * @param str the input string
 * @return the length of the longest substring with at most k distinct characters
 */

/** Approach 1: Brute Force
 * Generate all the subarray [substrings],
 * and check if the number of distinct characters in the substring is less than or equal to k.
 * TC: O(n^2) to generate all substrings and O(n) to check distinct characters in each substring
 * SC: O(n) for the set to store distinct characters in the worst case
 */
// int kDistinctChars(int k, string& str) {
//   int maxLength = 0;
//   for (int i = 0; i < str.size(); i++) {
//     unordered_set<char> distinctChars;
//     for (int j = i; j < str.size(); j++) {
//       distinctChars.insert(str[j]);
//       if (distinctChars.size() > k) {
//         break;
//       }
//       maxLength = max(maxLength, j - i + 1);
//     }
//   }

//   return maxLength;
// }

int kDistinctChars(int k, string& str) {
  int l = 0;
  int r = 0;
  int maxLength = 0;

  vector<int> freq(26, 0);
  int distinct = 0;

  while (r < str.size()) {
    if (freq[str[r] - 'a'] == 0) distinct++;
    freq[str[r] - 'a']++;

    while (distinct > k) {
      freq[str[l] - 'a']--;
      if (freq[str[l] - 'a'] == 0) distinct--;
      l++;
    }

    maxLength = max(maxLength, r - l + 1);
    r++;
  }

  return maxLength;
}

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string str;
    cin >> str;
    if (str[0] == '"') str = str.substr(1, str.size() - 2);  // Remove the surrounding quotes
    int result = kDistinctChars(k, str);
    cout << result << "\n";
  }

  return 0;
}