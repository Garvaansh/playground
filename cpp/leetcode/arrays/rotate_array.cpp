#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Working only for small test cases :(
    // Time complexity: O(n*k) 
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;

    //     while (k--) {
    //         int last = nums[n - 1];
    //         for (int i = n - 1; i > 0; --i) {
    //             nums[i] = nums[i - 1];
    //         }
    //         nums[0] = last;
    //     }
    // }
    /* !--------------------------------------------- */
    
    // Time complexity: O(n) Space complexity: O(n)
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> temp(n);
    //     for (int i = 0; i < n; ++i) {
    //         temp[(i + k) % n] = nums[i];
    //     }
    //     nums = temp;
    // }
    /* !--------------------------------------------- */
    
    /* Reverses the array,
    and then reverses the first k elements 
    and rest of the sub-array */
    // Time complexity: O(n) Space complexity: O(1) 
    void reverse(vector<int>& nums, int start, int end){
        while(start < end)
            swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

};
    

int main() {
    // Redirect cin to read from input.txt and cout to write to output.txt
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cerr << "Error opening input or output file.\n";
        return 1;
    }


    // input read 

    int t;
    fin >> t;
    
    Solution sol;

    for(int i = 1; i <= t; i++){
    int n, k;
    fin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    sol.rotate(arr, k);
    fout <<"Test Case " << i << ": " << endl;
    for(auto it: arr) fout << it << " ";
    fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}