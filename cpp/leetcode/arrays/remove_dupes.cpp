#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    pair<int, vector<int>> removeDuplicates(vector<int>& nums, int n) {
        vector<int> new_nums;
        int k = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] != nums[i]) {
                new_nums.push_back(nums[i]);
                k++;
                }
            }
            new_nums.push_back(nums[n - 1]);
            
            return {k + 1, new_nums};
        }
        
    // int removeDuplicates(vector<int>& nums) {
    //     // vector<int> new_nums;
    //     int k = 1, n = nums.size();
    //     for(int i = 1; i < n; i++) {
    //         if(nums[i] != nums[i - 1]) {
    //             // new_nums.push_back(nums[i]);
    //             nums[k++] = nums[i];
    //             }
    //         }
            
    //         return k;
    //     }
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
    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    pair<int, vector<int>> result = sol.removeDuplicates(arr, n);
    // int result = sol.removeDuplicates(arr);
    fout <<"Test Case " << i << ": " << result.first << endl;
    for(auto it: result.second) fout << it << " ";
    fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}