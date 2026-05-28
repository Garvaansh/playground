#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;
  cin >> t;
  while(t--) {
    cin >> n;

    // * Calculate number of digits to determine the power
    // * Armstrong number: sum of each digit raised to the power of total digits equals the number
    // * Example: 1634 has 4 digits, so 1^4 + 6^4 + 3^4 + 4^4 = 1634
    int digits = (int)log10(n) + 1;
    
    // ! Handle edge case: n = 0 (0 has 1 digit, 0^1 = 0, which is Armstrong)
    if(n == 0) {
      cout << "True" << endl;
      continue;
    }

    int sum = 0;
    int temp = n;
    while(temp != 0) {
      int digit = temp % 10;
      // * Use pow with the correct power (number of digits)
      sum += pow(digit, digits);
      temp /= 10;
    }

    cout << ((sum == n) ? "True" : "False") << endl;
  }

  return 0;
}