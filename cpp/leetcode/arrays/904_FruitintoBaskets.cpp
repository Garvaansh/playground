#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /** Approach 1: Brute  Force
   * Generate all subarrays, and
   * find the largest subarray  with at most 2 distinct elements
   * TC: O(n^2)
   * SC: O(3) for the set
   */
  // int totalFruit(vector<int>& fruits) {
  //   int maxLen = 0;

  //   for (int i = 0; i < fruits.size(); i++) {
  //     unordered_set<int> basket;
  //     int len = 0;
  //     for (int j = i; j < fruits.size(); j++) {
  //       if (basket.find(fruits[j]) == basket.end()) {
  //         if (basket.size() == 2) break;
  //         basket.insert(fruits[j]);
  //       }
  //       len++;
  //     }
  //     maxLen = max(maxLen, len);
  //   }
  //   return maxLen;
  // }

  /** Approach 2: Sliding  Window + Two pointers
   * Use a map to keep track of the count of each fruit in the current window
   * Use two pointers to maintain a window of at most 2 distinct fruits
   * TC: O(n) + O(n) = O(2n)
   * SC: O(3) for the map
   */
  // int totalFruit(vector<int>& fruits) {
  //   unordered_map<int, int> basket;
  //   int maxLen = 0, left = 0, right = 0;
  //   while (right < fruits.size()) {
  //     basket[fruits[right]]++;
  //     while (basket.size() > 2) {
  //       basket[fruits[left]]--;
  //       if (basket[fruits[left]] == 0) {
  //         basket.erase(fruits[left]);
  //       }
  //       left++;
  //     }
  //     maxLen = max(maxLen, right - left + 1);
  //     right++;
  //   }
  //   return maxLen;
  // }

  /** Approach 3: Sliding  Window + Two pointers (Optimized)
   * Use a map to keep track of the count of each fruit in the current window
   * Instead of using while loop to shrink from left,
   * we can directly move left pointer to the next position of the first fruit in the current window
   * therefore, shrinking and expanding the window in one step
   * TC: O(n)
   * SC: O(3) for the map
   */
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int maxLen = 0, left = 0, right = 0;
    while (right < fruits.size()) {
      basket[fruits[right]]++;
      if (basket.size() > 2) {
        basket[fruits[left]]--;
        if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
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
    int n;
    cin >> n;
    vector<int> fruits(n);
    for (int i = 0; i < n; i++) {
      cin >> fruits[i];
    }
    cout << Solution().totalFruit(fruits) << endl;
  }

  return 0;
}