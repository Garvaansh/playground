#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int firstUniqueEven(vector<int>& nums) {
    int res = -1;
    unordered_map<int, int> freq;

    for (int num : nums) {
      if (num & 1) continue;  // skip odd numbers
      freq[num]++;
    }

    for (int num : nums) {
      if (num & 1) continue;  // skip odd numbers
      if (freq[num] == 1) {
        res = num;
        break;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int result = sol.firstUniqueEven(arr);
    cout << result << "\n";
  }

  return 0;
}