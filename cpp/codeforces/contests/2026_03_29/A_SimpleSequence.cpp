#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> SimpleSequence(int n) {
    vector<int> result;
    for (int i = n; i >= 1; i--) {
      result.push_back(i);
    }
    return result;
  }
};

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> sequence = Solution().SimpleSequence(n);
    for (int num : sequence) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}