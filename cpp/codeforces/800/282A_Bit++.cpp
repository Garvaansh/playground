#include <bits/stdc++.h>
using namespace std; 

int computeResult(vector<string>& statements) {
  // * Approach: Batch Processing with Counting
  // * Logic: Store all input strings in a vector, then count '+' and '-' occurrences in one pass.
  // * Compute result as plus - minus for net increments.
  // * Time Complexity: O(n) - single pass through all statements.
  // * Space Complexity: O(n) - stores all input strings.
  // * Pros: Reduces function call overhead, processes in batch for better efficiency.
  // ! Cons: Uses more memory for large n, but n<=150 so fine.
  // ? Note: Assumes valid inputs; no error handling for simplicity.
  int plus = 0, minus = 0;
  for(auto& s : statements) {
    if(s[1] == '+') plus++;
    else minus++;
  }
  return plus - minus;
}

int main() {
  int n;
  cin >> n;
  vector<string> statements(n);
  for(int i = 0; i < n; i++) {
    cin >> statements[i];
  }
  int res = computeResult(statements);
  cout << res << endl;

    return 0;
}