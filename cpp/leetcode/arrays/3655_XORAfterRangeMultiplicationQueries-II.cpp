#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
   public:
    const int MOD = 1e9 + 7;

    // Binary exponentiation using fermat's little theorem for modular inverse
    ll modExp(ll base, ll exp) {
        ll result = 1;
        base = base % MOD;

        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            exp = exp >> 1;
            base = (base * base) % MOD;
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), blockSize = ceil(sqrt(n));

        // For small k, store the indices affected by each k
        unordered_map<int, vector<vector<int>>> smallKmap;

        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            // Larger k, so brute force works
            if (k >= blockSize) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                smallKmap[k].push_back(it);
            }
        }

        // Process small k queries
        for (auto& [k, it] : smallKmap) {
            vector<ll> diff(n, 1);

            for (auto& i : it) {
                int l = i[0];
                int r = i[1];
                int v = i[3];

                diff[l] = (diff[l] * v) % MOD;
                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;
                if (next < n) diff[next] = (diff[next] * modExp(v, MOD - 2)) % MOD;
            }

            // Cumulative product to apply the multiplications
            for (int i = 0; i < n; i++) {
                if ((i - k) >= 0) diff[i] = (diff[i] * diff[i - k]) % MOD;
            }

            // Apply the final multipliers to nums
            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        // calculate the XOR of nums[i]
        int res = 0;
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