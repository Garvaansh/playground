#include <bits/stdc++.h>
using namespace std; 

int count_years(int n, int m) {
  int years = 0;
  while (n <= m) {
    n *= 3;
    m *= 2;
    years++;
  }
  return years;
}

int main() {
        int n, m;
        cin >> n >> m;
        cout << count_years(n, m) << endl;
    
    return 0;
}