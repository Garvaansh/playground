#include <bits/stdc++.h>
using namespace std; 

int calculateXOR(int a, int b) {
    
  // Approach 1: Using a for loop with XOR
  // Iterate from a to b, XOR each number with result.
  // Example: a=1, b=3
  // res=0
  // a=1: res ^=1 ->1, a=2
  // a=2: res ^=2 ->3, a=3
  // a=3: res ^=3 ->0
  // Time: O(b-a+1)
  // Space: O(1)
    int res = 0;
    while(a <= b) {
        res ^= a;
        a++;  
    } 
    return res;

   // Approach 2: Using XOR properties and patterns
   // Pattern for XOR from 0 to n:
   // n % 4 == 0 -> n
   // n % 4 == 1 -> 1
   // n % 4 == 2 -> n + 1
   // n % 4 == 3 -> 0
   // XOR(a to b) = XOR(0 to b) ^ XOR(0 to a-1)
   // Example: a=1, b=3
   // XOR(0 to 3)=0 (3%4=3), XOR(0 to 0)=0 (0%4=0), 0^0=0
   // Time: O(1)
   // Space: O(1)
  /*  Pattern observed for XOR from 0 to n:
    n % 4 == 0 -> result is n
    n % 4 == 1 -> result is 1
    n % 4 == 2 -> result is n + 1
    n % 4 == 3 -> result is 0

    Using this pattern, we can calculate XOR from a to b as:
    XOR(a to b) = XOR(0 to b) ^ XOR(0 to a-1)  */
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << calculateXOR(a, b) << endl;
  }

    return 0;
}