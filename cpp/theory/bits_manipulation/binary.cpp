#include <bits/stdc++.h>
using namespace std; 

class binary {
  // Approach: Convert decimal to binary by repeatedly dividing by 2 and collecting remainders.
  // Start from LSB (least significant bit), build string in reverse, then reverse it.
  // Time: O(log n) - number of bits in n.
  // Space: O(log n) - for the result string.
  // Edge case: n=0 returns "0".
  string decimal2binary(int n) {
    if (n == 0) return "0";  // Special case for 0
    string res = "";
    while(n > 0) {
      res += to_string(n % 2);
      n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
  }

  // Approach: Convert binary string to decimal by processing from right to left (LSB to MSB).
  // Use a power variable starting at 1 (2^0), multiply by 2 each step.
  // Time: O(n) - where n is string length.
  // Space: O(1) - constant extra space.
  // Assumes valid binary string (only '0' and '1').
  int binary2decimal(string s) {
    int res = 0;
    int power = 1; // 2^0

    for(int i = s.length() - 1; i >= 0; i--) {
      if(s[i] == '1') {
        res += power;  // Add current power if bit is 1
      }
      power *= 2;  // Next power: 2^1, 2^2, etc.
    }
    return res;
  }
  
  public:
  binary() {
    int choice;
    cout << "What type of conversion you want to perform?\n1. Decimal to Binary\n2. Binary to Decimal\n";
    cin >> choice;

    switch (choice) {
      case 1: {
        int n;
        cout << "Enter a decimal number: ";
        cin >> n;

        cout << "Binary nummber of " << n << " is: " << decimal2binary(n) << endl;
        break;
      }

      case 2: {
        string s;
        cout << "Enter a binary number: ";
        cin >> s;

        cout << "Decimal nummber of " << s << " is: " << binary2decimal(s) << endl;
        break;
      }

      default:
        cout << "Invalid Choice!" << endl;
    }
  }
};


int main() {
  int t;
  cin >> t;

  while(t--) {
    binary b;
  }

    return 0;
}