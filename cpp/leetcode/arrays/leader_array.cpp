#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rev(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < nums.size()/2; i++ ){
            nums[i] ^= nums[n - i - 1];
            nums[n - i - 1] ^= nums[i];
            nums[i] ^= nums[n - i - 1];
        }
    }

    vector<int> leaders(vector<int>& nums) {
      vector<int> ans;
      int maxi = INT_MIN;
      for(int i = nums.size() - 1; i >= 0; i-- ){
        if(nums[i] > maxi){
            ans.push_back(nums[i]);
            maxi = max(maxi, nums[i]);
        }
      }
      rev(ans);
      return ans;
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

  Solution sol;
  int i = 1;
  while(t--){
    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      fin >> arr[i];
    }

    vector<int> ans = sol.leaders(arr);
    fout << "Leaders " << i++ << ": " ;
    for(auto it: ans) fout << it << " ";
    fout << endl;
  }

  fin.close();
  fout.close();

  return 0;
}

