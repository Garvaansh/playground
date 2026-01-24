#include <bits/stdc++.h>
using namespace std; 

class binary {
  // Approach 1: Convert decimal to binary by repeatedly dividing by 2 and collecting remainders.
  // Start from LSB (least significant bit), build string in reverse, then reverse it.
  // Example: Take n=5.
  // 5 / 2 = 2 rem 1
  // 2 / 2 = 1 rem 0
  // 1 / 2 = 0 rem 1
  // Reverse: 101
  // Time: O(log n)
  // Space: O(log n)
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

  // Approach 2: Convert binary string to decimal by processing from right to left (LSB to MSB).
  // Use a power variable starting at 1 (2^0), multiply by 2 each step.
  // Example: Take s="101".
  // i=2 (s[2]='1'): res += 1 * 1 = 1, power = 2
  // i=1 (s[1]='0'): res += 0, power = 4
  // i=0 (s[0]='1'): res += 1 * 4 = 4, total res=5
  // Time: O(n)
  // Space: O(1)
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