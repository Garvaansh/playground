#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> minDistinctFreqPair(vector<int>& nums) {
    if (nums.size() < 2) return {-1, -1};

    vector<int> freq(101, 0);

    for (int num : nums) {
      freq[num]++;
    }

    // iterate values directly
    for (int x = 1; x <= 100; x++) {
      if (freq[x] == 0) continue;

      for (int y = x + 1; y <= 100; y++) {
        if (freq[y] == 0) continue;

        if (freq[x] != freq[y]) {
          return {x, y};
        }
      }
    }

    return {-1, -1};
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    vector<int> ans = Solution().minDistinctFreqPair(nums);
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }
  return 0;
}