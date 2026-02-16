#include <bits/stdc++.h>
using namespace std; 

void swap(int &a, int &b){
  if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void insertion_sort(vector<int> &arr, int i, int n){
    if(i == n) return; // Base condition
    int j = i;
    while(j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
      j--;
    }
    insertion_sort(arr, i + 1, n);
  }

int main(){
  vector<int> arr = {3, 1, 4, 2, 5};
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

  insertion_sort(arr,0 , n);

  cout << "Sorted Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

    return 0;
}