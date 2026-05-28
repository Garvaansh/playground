#include <bits/stdc++.h>
using namespace std; 

bool dbmb(int n, int s, int x, vector<int>& a) {
  int sum = 0;
  for(int i : a) sum += i;

  //check if s is matched
  if(sum == s) return true;
  else if (sum > s) return false;
  else {
    return ((s - sum) % x == 0);
  }
}


int main() {
  int t;
  cin >> t;
  while (t--) {
  int n, s, x;
  cin >> n >> s >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    }
  
    cout << (dbmb(n, s, x, a) ? "YES" : "NO") << "\n";
  }
    return 0;
}