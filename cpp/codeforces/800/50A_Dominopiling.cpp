#include <bits/stdc++.h>
using namespace std; 

int possible(int n, int m) {
  return (n * m) / 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << possible(n, m) << endl;

    return 0;
}