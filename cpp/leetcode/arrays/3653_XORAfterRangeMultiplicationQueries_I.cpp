#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res = 0;
        const int MOD = 1e9 + 7;

        int i = 0;
        // Simulate the queries
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }

        // Calculate XOR of all elements in nums
        for (int i : nums)
            res ^= i;

        return res;
    }
};

vector<int> parseArray(string s) {
    vector<int> res;
    int num = 0;
    bool inNum = false;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            inNum = true;
        } else {
            if (inNum) {
                res.push_back(num);
                num = 0;
                inNum = false;
            }
        }
    }
    return res;
}

vector<vector<int>> parse2DArray(string s) {
    vector<vector<int>> res;
    vector<int> curr;
    int num = 0;
    bool inNum = false;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            inNum = true;
        } else if (c == ',' || c == ']') {
            if (inNum) {
                curr.push_back(num);
                num = 0;
                inNum = false;
            }
            if (c == ']' && !curr.empty()) {
                res.push_back(curr);
                curr.clear();
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    string numsLine, queriesLine;

    while (getline(cin, numsLine)) {
        if (numsLine.empty()) continue;

        getline(cin, queriesLine);

        vector<int> nums = parseArray(numsLine);
        vector<vector<int>> queries = parse2DArray(queriesLine);

        cout << sol.xorAfterQueries(nums, queries) << "\n";
    }

    return 0;
}