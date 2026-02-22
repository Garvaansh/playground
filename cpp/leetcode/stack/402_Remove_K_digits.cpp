#include <bits/stdc++.h>
using namespace std; 

/** Remove K Digits
 * ? Remove exactly k digits from the numeric string `num` to produce the smallest possible number.
 * ! Algorithm: maintain a monotonic increasing stack; while current digit is smaller than stack top and k>0, pop to remove larger digits.
 * ! After the main scan, remove remaining k digits from the end, then build result, trim leading zeros and reverse.
 * ! Time (worst-case): O(5n) where n = num.length() (initial scan + possible extra pops + build/trim/reverse), which simplifies to O(n) asymptotically.
 * ! Space: O(n) for stack and result string.
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        //* Edge case: if k removes all digits, result is 0
        if(num.size() <= k) return "0";

        //* Use a monotonic increasing stack of characters to keep smallest possible digits
        stack<char> st;

        //* Main pass: try to remove larger previous digits when a smaller digit arrives
        for(char c : num) {
          //* While top is greater than current digit and we still can remove, pop it
          while(!st.empty() && st.top() > c && k > 0) {
            st.pop();
            k--;
          }
          //* Push current digit (may be removed later if a smaller digit appears)
          st.push(c);
        }

        //* If removals remain, remove from the end (largest remaining digits)
        while(k > 0 && !st.empty()) {
          st.pop();
          k--;
        }

        //* Build result string from stack (currently reversed order)
        string res = "";
        while(!st.empty()) {
          res += st.top();
          st.pop();
        }

        //* Trim leading zeros from the final number (they are trailing in `res` before reverse)
        while(res.size() > 1 && res.back() == '0') res.pop_back();

        //* Reverse to restore original left-to-right order and return
        reverse(res.begin(), res.end());
        
        return res;
    }
};

int main() {
  int t;
  cin >> t;
  while(t--) {
    string num;
    int k;
    cin >> num;
    cin >> k;
    cout << Solution().removeKdigits(num.substr(1, num.size() - 2), k) << endl;
  }
    return 0;
}