#include <bits/stdc++.h>
using namespace std;

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool found = false;


    auto query = [&](int i, int j) -> int {
      cout << "? " << i << " " << j << "\n";
      cout.flush();
      int res;
      cin >> res;
      if (res == -1) exit(0);
      return res;
    };

    for (int i = 1; i <= n + 1; i += 2) {
      int res = query(i, i + 1);

    if (res == 1) {
      // both are zero
      cout << "! " << i << endl;
      cout.flush();
      break;
    }
  }
}

return 0;
}