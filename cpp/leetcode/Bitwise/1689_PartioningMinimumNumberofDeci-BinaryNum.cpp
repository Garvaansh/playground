#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  /* Approach 1: Brute Force
   *  Subtracting the maximum possible deci-binary num '1', '11', '111' ...
   */
  // int minPartitions(string n) {
  //     int cnt = 0;
  //     while (true) {
  //         bool isChanged = false;
  //         for(char& c : n) {
  //             if(c != '0') {
  //              c--; // Decrement c by 1
  //             isChanged = true;
  //             }
  //         }

  //         if(!isChanged) break;
  //         cnt++;
  //     }
  //     return cnt;
  // }

  /* Approach 2: Return the maximum element present in the string
   * Intuition: we can decrease a num at max by 1.
   */
  int minPartitions(string n) { 
    return *max_element(begin(n), end(n)) - '0'; 
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    cout << Solution().minPartitions(n) << endl;
  }
  return 0;
}