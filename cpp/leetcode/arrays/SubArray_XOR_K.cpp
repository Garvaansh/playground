#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int SubArrayXOR(vector<int>& arr, int x){

  // Brute force approach --> 

      // int n = arr.size();
      // int count = 0;
      // for(int i = 0; i < n; i++){
      //   int xor_ = 0;
      //   for(int j = i; j < n; j++){
      //     xor_ = xor_ ^ arr[j];
      //     if(xor_ == x){
      //       count++;
      //     }
      //   }
      // }
      // return count;

  // -------------------------------------------------//

  // Optimal Approach -->
  unordered_map<int, int> mp = {{0, 1}};
  int count = 0, preXOR = 0;
  for(int i = 0; i < arr.size(); i++){
      preXOR = preXOR ^ arr[i];
      
      int required = preXOR ^ x;
      if(mp.find(required) != mp.end()){
        count += mp[required];
        }
      mp[preXOR]++;
      }
      return count;
    }
};

int main(){
  int t, n, x;
  cin >> t;
  Solution sol;
  
  while(t--){
  static  int i = 1;
  cin >> n >> x;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  cout << "Test Case " << i++ << ": " << sol.SubArrayXOR(arr, x) << endl;
  }
}