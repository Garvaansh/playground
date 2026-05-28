#include <bits/stdc++.h>
using namespace std; 

class Solution{
  public:
  void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid <= high){
      if(nums[low] == 0) low++;
      if(nums[high] == 2) high--;
      if(nums[mid] == 0 && low < mid)
        swap(nums[low++], nums[mid++]);
      else if(nums[mid] == 2 && mid < high)
        swap(nums[high--], nums[mid]);
      else mid++;
    }
  }
};

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  if (!fin || !fout) {
    cerr << "Error opening input or output file.\n";
    return 1;
  }
  int t;
  fin >> t;
  Solution sol;
  while(t--){
    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      fin >> arr[i];
    }

    sol.sortColors(arr);
    fout << "Sorted Array: " << endl;
    for(auto it: arr) fout << it << " ";
    fout << endl;
  }
  fin.close();
  fout.close();

    return 0;
}