#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int reverse(int n) {
    if ((int)(log10(n) + 1) == 1) return n;

      return ((n % 10) * 10) + reverse(n / 10);
    }
};

int main() {
    // Disable standard input and output synchronization for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << Solution().reverse(1234) << endl; // Output: 4321

    return 0;
}