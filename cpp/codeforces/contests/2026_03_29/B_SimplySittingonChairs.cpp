#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countPairs(vector<int>& nums) {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
      if (nums[i] <= i + 1) count++;
    }

    return count;
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution sol;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    cout << sol.countPairs(nums) << endl;
  }

  return 0;
}