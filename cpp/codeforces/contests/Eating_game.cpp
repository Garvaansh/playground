// Problem link: https://codeforces.com/contest/2200/problem/A

#include <bits/stdc++.h>
using namespace std;

/**
 * could be solved without hashmap as:
 * if(arr[i] > maxi) {
 *  maxi = arr[i];
 * count = 1;  resetting the count for the new maximum
 * }
 * if(arr[i] == maxi) count++;
 * 
 * i was just dumb to not think of this before :sobs:
 */

class Solution {
 public:
  int maximumPlayers(vector<int>& arr) {
    int maxi = arr[0];
    unordered_map<int, int> count;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] > maxi) {
        maxi = arr[i];
      }
      count[arr[i]]++;
    }

    return count[maxi];
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
    cout << ((n < 2) ? n : Solution().maximumPlayers(arr)) << endl;
  }

  return 0;
}