#include <bits/stdc++.h>
using namespace std; 

void swap(int &a, int &b){
  if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void bubble_sort(vector<int> &arr, int n){
  if(n == 0) return; // Base condition
  for(int j = 0; j <= n - 1; j++)
      if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
  
  bubble_sort(arr, n - 1);
}

int main(){
  vector<int> arr = {3, 1, 4, 5, 8, 2};
  int n = arr.size() - 1;
  // cout << "Enter the number of elements: ";
  // cin >> n;

  // cout << "Enter the elements: ";
  // for(int i = 0; i < n; i++){
  //     int x;
  //     cin >> x;
  //     arr.push_back(x);
  // }

  cout << "Original Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

  bubble_sort(arr, n);

  cout << "Sorted Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

    return 0;
}