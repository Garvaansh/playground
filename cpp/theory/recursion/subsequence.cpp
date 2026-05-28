#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // ! Approach 1: with helper function
    // void subset(int i, string& s, string curr, vector<string>& res) {
    //     if (i == s.size()) {
    //         res.push_back(curr);
    //         return;
    //     }

    //     // include current char
    //     subset(i + 1, s, curr + s[i], res);

    //     // exclude current char
    //     subset(i + 1, s, curr, res);
    // }

    // vector<string> generate(string& s) {
    //     vector<string> res;
    //     subset(0, s, " ", res);
    //     return res;
    // }

    // ! Approach 2: without helper function
    vector<string> generate(string s) {
        if (s.empty()) {
            return {""};
        }

        char ch = s[0];
        string rest = s.substr(1);

        vector<string> temp = generate(rest);
        vector<string> res;

        for (auto& str : temp) {
            res.push_back(ch + str);    // include
            res.push_back(str);         // exclude
        }

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
        string s;
        cin >> s;

        vector<string> res = sol.generate(s);
        cout << "[";
        for (size_t i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i != res.size() - 1) {
                cout << ",";
            }
        }
        cout << "]\n";
    }

    return 0;
}