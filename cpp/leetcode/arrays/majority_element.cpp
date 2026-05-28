#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int Majorityelement(vector<int>& nums){
      int ele, count = 0;
      for(int i = 0; i < nums.size(); i++){
        if(count ==0){
          count = 1;
          ele = nums[i];
        }
        else if(nums[i] != ele) count--;
        else count++;
      }

      int cnt = 0;
      for(int i = 0; i < nums.size(); i++){
        if(nums[i] == ele) cnt++;
      }
      if(cnt > nums.size()/2)
        return ele;

    return -1;
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
    int result = sol.Majorityelement(arr);
    fout <<"Test case " << i++ << ": " << result << endl;
  }

  fin.close();
  fout.close();

  return 0;
}