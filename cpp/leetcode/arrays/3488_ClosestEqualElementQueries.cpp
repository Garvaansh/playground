#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int size = queries.size();
        vector<int> result(size);

        // Build the index Map for nums
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (int i = 0; i < size; i++) {
            int q = queries[i];
            int minDis = INT_MAX;
            auto& vec = mpp[nums[q]];

            int pos = lower_bound(vec.begin(), vec.end(), q) - vec.begin();

            int sz = vec.size();
            if (sz == 1) {
                result[i] = -1;
                continue;
            }

            // Right neighbor || pos + 1
            int right = vec[(pos + 1) % sz];
            int diff = abs(q - right);
            minDis = min({minDis, diff, n - diff});

            // Left neighbor || pos - 1
            int left = vec[(pos - 1 + sz) % sz];
            diff = abs(q - left);
            minDis = min({minDis, diff, n - diff});
            result[i] = minDis;
        }

        return result;
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
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }

        vector<int> result = sol.solveQueries(nums, queries);
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i < result.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}