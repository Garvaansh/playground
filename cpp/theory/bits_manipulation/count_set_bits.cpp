#include <bits/stdc++.h>
using namespace std; 

int count_set_bits(int n) {
  // Approach 1: Brute force - check each bit
  // Loop while n > 0, check if LSB is 1, count it, right shift.
  // Example: n=5 (101)
  // 5 % 2 =1, count=1, n=2
  // 2 % 2=0, n=1
  // 1 % 2=1, count=2, n=0
  // Time: O(log n)
  // Space: O(1)
  // int count = 0;
  // while (n) {
  //   if(n % 2 == 1) {
  //     count++;
  //   }
  //   n /= 2;
  // }
  // if (n== 1) {
  //   count++;
  // }
  // return count;

  // Approach 2: Bitwise manipulation - turn off rightmost set bit
  // While n > 0, n &= (n-1) clears lowest set bit, increment count.
  // Example: n=5 (101)
  // n = 101 & 100 = 100, count=1
  // n = 100 & 011 = 000, count=2
  // Time: O(number of set bits)
  // Space: O(1)
  int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << count_set_bits(n) << "\n";
    }

    return 0;
}