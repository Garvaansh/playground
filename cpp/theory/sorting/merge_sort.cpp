#include <bits/stdc++.h>
using namespace std; 

void merge(vector<int> &arr, int low, int mid, int high){
  vector<int> temp;
  int left = low, right = mid + 1;

  while(left <= mid && right <= high){
    if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
    else temp.push_back(arr[right++]);
  }
  while(left <= mid) temp.push_back(arr[left++]);
  while(right <= high) temp.push_back(arr[right++]);

  for(int i = low; i <= high; i++) arr[i] = temp[i - low];
}

void merge_sort(vector<int> &arr, int low, int high){
  if(low >= high) return;
  int mid = (low + high)/2;

  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}


int main(){
  vector<int> arr = { 2, -1, 0 ,4, 3, 5};
  // int n;
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

  merge_sort(arr, 0, arr.size() - 1);

  cout << "Sorted Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

    return 0;
}