#include <bits/stdc++.h>
using namespace std; 

int count_if(int& n, int& k,vector<int>& scores) {
  int count = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(scores[i] > 0 && scores[i] >= scores[k - 1]) count++;
  }

  return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> scores(n);
    for(int i = 0; i < n; i++) {
      cin >> scores[i];
    }

    cout << count_if(n, k, scores) << endl;

    return 0;
}