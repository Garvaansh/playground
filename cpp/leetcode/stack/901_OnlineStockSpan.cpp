#include <bits/stdc++.h>
using namespace std;

#
/**
 * Intuition: Use a stack to keep track of previous prices and their spans, so we can efficiently find how many consecutive days the price was less than or equal to today.
 * Approach: For each new price, pop from the stack while the top price is less than or equal to current, summing their spans, then push the current price and its span.
 * Time Complexity: O(2n) — each price is pushed and popped from the stack at most once.
 * Space Complexity: O(n) — stack stores at most n elements in the worst case.
 */
class StockSpanner {
  stack<pair<int, int>> st;  // pair<price, span>
 public:
  StockSpanner() {}

  int next(int price) {
    int span = 1;
    while (!st.empty() && st.top().first <= price) {
      span += st.top().second;
      st.pop();
    }
    st.push({price, span});
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    StockSpanner obj;
    vector<int> res;

    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      res.push_back(obj.next(val));
    }

    cout << "[";
    for (int x : res)
      cout << x << " ";
    cout << "]";
    cout << endl;
  }

  return 0;
}