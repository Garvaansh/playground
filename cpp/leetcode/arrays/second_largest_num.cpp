#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            int maxi = INT_MIN, sec_maxi = INT_MIN;
            
            for (int it : nums) {
                if (it > maxi) {
                    sec_maxi = maxi;
                    maxi = it;
                } else if (it < maxi && it > sec_maxi) {
                    sec_maxi = it;
                }
            }
    
            return (sec_maxi == INT_MIN) ? -1 : sec_maxi;
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

    int result = sol.secondLargestElement(arr);
    fout <<"Second Larget num: " << result << endl;
    }

    fin.close();
    fout.close();

    return 0;
}