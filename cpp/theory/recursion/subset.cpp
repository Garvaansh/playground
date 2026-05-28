#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

class Solution {
   public:
    void solve(vector<int> processed, vector<int> nums, vvi& res) {
        if (nums.size() == 0) {
            res.push_back(processed);
            return;
        }

        int n = nums[0];
        vector<int> rest(nums.begin() + 1, nums.end());

        solve(processed, rest, res);
        processed.push_back(n);
        solve(processed, rest, res);
    }

    vvi subsets(vector<int>& nums) {
        vvi res;

        solve({}, nums, res);
        return res;
    }
};

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> list(n);
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }

        vvi res = sol.subsets(list);
        for (const auto& subset : res) {
            cout << "[";
            for (size_t i = 0; i < subset.size(); i++) {
                cout << subset[i];
                if (i < subset.size() - 1) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}