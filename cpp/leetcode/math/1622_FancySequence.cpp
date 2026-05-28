#include <bits/stdc++.h>
using namespace std;

class Fancy {
 public:
  using ll = long long;
  const int mod = 1e9 + 7;

  vector<int> list;
  ll add = 0;
  ll mul = 1;

  /**
   * Constructor: Initializes the Fancy object.
   * Intuition: Set up the initial values for addition and multiplication factors.
   * TC: O(1) as no significant computation is performed.
   * SC: O(1) as no additional space is used.
   */
  Fancy() {}

  /**
   * power: Computes x raised to the power n modulo mod.
   * Intuition: Use modular exponentiation to efficiently calculate large powers.
   * TC: O(log n) due to repeated squaring.
   * SC: O(1) as no additional space is used.
   */
  ll power(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
      if (n % 2 == 1) {  // If n is odd
        res = (res * x) % mod;
        n--;
      } else {  // If n is even
        x = (x * x) % mod;
        n /= 2;
      }
    }
    return res;
  }

  /**
   * append: Adds a value to the sequence after applying reverse operations.
   * Intuition: Reverse the effect of current addition and multiplication factors to store the
   * original value. TC: O(log mod) due to modular inverse calculation. SC: O(1) as no additional
   * space is used.
   */
  void append(int val) {
    val = ((val - add) % mod + mod) % mod;
    val = (val * power(mul, mod - 2)) % mod;
    list.push_back(val);
  }

  /**
   * addAll: Increments all elements in the sequence by a given value.
   * Intuition: Update the addition factor to reflect the increment.
   * TC: O(1) as the operation is performed in constant time.
   * SC: O(1) as no additional space is used.
   */
  void addAll(int inc) { add = (add + inc) % mod; }

  /**
   * multAll: Multiplies all elements in the sequence by a given value.
   * Intuition: Update both the multiplication and addition factors to reflect the scaling.
   * TC: O(1) as the operation is performed in constant time.
   * SC: O(1) as no additional space is used.
   */
  void multAll(int m) {
    mul = (mul * m) % mod;
    add = (add * m) % mod;
  }

  /**
   * getIndex: Retrieves the value at a given index after applying all operations.
   * Intuition: Apply the current addition and multiplication factors to the stored value.
   * TC: O(1) as the retrieval and computation are performed in constant time.
   * SC: O(1) as no additional space is used.
   */
  int getIndex(int idx) {
    if (idx >= list.size()) return -1;
    return (list[idx] * mul + add) % mod;
  }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  /** Input format:
   * Fancy
    append 2
    addAll 3
    append 7
    multAll 2
    getIndex 0
    addAll 3
    append 10
    multAll 2
    getIndex 0
    getIndex 1
    getIndex 2
   */

  Fancy* obj = nullptr;

  string op;
  vector<string> output;

  while (cin >> op) {
    if (op == "Fancy") {
      obj = new Fancy();
      output.push_back("null");
    } else if (op == "append") {
      int v;
      cin >> v;
      obj->append(v);
      output.push_back("null");
    } else if (op == "addAll") {
      int v;
      cin >> v;
      obj->addAll(v);
      output.push_back("null");
    } else if (op == "multAll") {
      int v;
      cin >> v;
      obj->multAll(v);
      output.push_back("null");
    } else if (op == "getIndex") {
      int v;
      cin >> v;
      int ans = obj->getIndex(v);
      output.push_back(to_string(ans));
    }
  }

  cout << "[";
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
    if (i != output.size() - 1) cout << ",";
  }
  cout << "]\n";

  return 0;
}