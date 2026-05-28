#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
 public:
  ll gcd(int m, int n) {
    while (m > 0 && n > 0) {
      ((m > n) ? m %= n : n %= m);
    }
    if (m == 0) return n;
    return m;
  }

  long long gcdSum(vector<int>& nums) {
    vector<int> prefixGCD(nums.size());
    prefixGCD[0] = gcd(nums[0], nums[0]);
    ll max_num = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      max_num = max(max_num, (ll)nums[i]);
      prefixGCD[i] = gcd(max_num, nums[i]);
    }

    sort(prefixGCD.begin(), prefixGCD.end());
    ll sum = 0;
    int left = 0, right = prefixGCD.size() - 1;
    while (left < right) {
      sum += gcd(prefixGCD[left++], prefixGCD[right--]);
    }

    return sum;
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    ll result = sol.gcdSum(arr);
    cout << result << "\n";
  }

  return 0;
}