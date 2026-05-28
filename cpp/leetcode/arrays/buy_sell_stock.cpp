#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxProfit(vector<int>& prices){
      int max_profit = INT_MIN;
      int left = 0, right = 0;
      while(right < prices.size()){
        if(prices[right] < prices[left]) left = right;
        int profit = prices[right] - prices[left];
        max_profit = max(max_profit, profit);
        right++;
      }
      return (left < right) ? max_profit : 0;
    }
};

int main(){
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  if (!fin || !fout) {
    cerr << "Error opening input or output file.\n";
    return 1;
  }

  int t;
  fin >> t;
  int i = 1;
  Solution sol;

  while(t--){
    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      fin >> arr[i];
    }

    int result = sol.maxProfit(arr);
    fout << "Test case " << i++ << ": " << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
  }
