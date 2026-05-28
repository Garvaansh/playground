#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Merge sort algo for the main problem function -->
  long long int merge(vector<int> &nums, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid + 1;

    // declaring count to find the pairs
    int count = 0;
    //merging and storing the array in temp
    while(left <= mid && right <= high){
      if(nums[left] <= nums[right]) temp.push_back(nums[left++]);
      else {
        count += mid - left + 1;
        temp.push_back(nums[right++]);
      }
    }
    
    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);
    for(int i = low; i <= high; i++) nums[i] = temp[i - low];
    return count;
  }

  long long int mergeSort(vector<int> &nums, int left, int right){
    long long int count = 0;
    if(left >= right) return count;
    int mid = (left + right)/2;
    count += mergeSort(nums, left, mid);
    count+= mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);
    return count;
  }
    long long int numberOfInversions(vector<int> &nums) {
// Brute Force -->

    // int n = nums.size();
    // long long int count = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if( nums[i] > nums[j] && i < j) count++; 
    //     }
    // }
    // return count;
// ------------------------------------------------------------ // 
// Optimnal solution - Merge Sort -->
    
    return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
  int t, n;
  cin >> t;
  
  Solution sol;
  while(t--){
  cin >> n;
  vector<int> nums(n);
  for(int &i : nums ) cin >> i;
  static int i = 1;
  long long ans = sol.numberOfInversions(nums);
  cout << "Test case "<< i++ << ": " << ans << endl;
  }
  return 0;
}