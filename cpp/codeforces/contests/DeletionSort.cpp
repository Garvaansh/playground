// Problem  link: https://codeforces.com/contest/2200/problem/B

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minElementsRem(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        return 1;
      }
    }
    return arr.size();
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    cout << ((n < 2) ? n : Solution().minElementsRem(arr)) << endl;
  }

  return 0;
}