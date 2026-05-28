#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums, int n){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] > nums[(i + 1) % n]) 
                    count++;
            }
            return count <= 1;
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
    int n;
    fin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    bool result = sol.check(arr, n);
    fout <<"Test Case " << i << ": " << (result ? "true" : "false") << endl;
    }

    fin.close();
    fout.close();

    return 0;
}