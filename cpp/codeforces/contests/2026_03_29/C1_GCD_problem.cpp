#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int maxop(vector<int>& arr) {
    vector<int> gcd_arr(arr.size());
    for (int i = 0; i < arr.size() - 1; i++) {
      gcd_arr[i] = gcd(arr[i], arr[i + 1]);
    }

    int max_op = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (gcd_arr[i] == arr[i]) continue;
      
    }
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // Write your code here

  return 0;
}