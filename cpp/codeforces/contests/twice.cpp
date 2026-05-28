// Problem link: https://codeforces.com/contest/2198/problem/A

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int twice(vector<int>& arr) {
    unordered_set<int> seen;
    int count = 0;

    if(arr.size() < 2) return 0; // No duplicates possible

    for(int num : arr) {
      if (seen.count(num)) {
        count++;  // Found the duplicate
      }
      seen.insert(num);
    }
    return count;
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
    cout << Solution().twice(arr) << endl;
  }

  return 0;
}