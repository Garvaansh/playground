#include <bits/stdc++.h>
using namespace std; 

vector<char> freqMap(string& s) {
  vector<char> freq(4);
  for(auto i : s) {
    if(i == '+') continue;
    else if(i == '1') freq[1]++;
    else if(i == '2') freq[2]++;
    else if(i == '3') freq[3]++;
  }
  return freq;
}

string sortedStr(string& s) {
  if(s.size() == 1) return s;
  vector<char> freq = freqMap(s);
  string res;
  for(int i = 1; i <= 3; i++) {
    while(freq[i]--) {
      res += to_string(i);
      res += '+';
    }
  }
  if(!res.empty() && res.back() == '+') {
    res.pop_back();
  }
  return res;
}

int main() {
    string s;
    cin >> s;

    cout << sortedStr(s) << endl;
  

    return 0;
}