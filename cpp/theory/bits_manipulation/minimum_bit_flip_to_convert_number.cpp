#include <bits/stdc++.h>
using namespace std; 

int minimum_flips(int start, int goal) {
  // Approach 1: XOR start and goal, count set bits in result
  // XOR shows differing bits; count 1s in XOR result.
  // Example: start=5 (101), goal=3 (011)
  // 101 ^ 011 = 110
  // Count set bits in 110: 2
  // Time: O(log n)
  // Space: O(1)
  int ans = start ^ goal;
  int count = 0;

  while(ans > 0) {
    ans &= (ans - 1);
    count++; 
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int start, goal;
    cin >> start >> goal;
    cout << minimum_flips(start, goal) << "\n";
    }

    return 0;
}