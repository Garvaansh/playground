#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int col = encodedText.size() / rows;

        vector<vector<char>> matrix(rows, vector<char>(col));
        for (int i = 0; i < encodedText.length(); i++) {
            matrix[i / col][i % col] = encodedText[i];
        }

        string res;
        for (int j = 0; j < col; j++) {
            for (int i = 0, k = j; i < rows && k < col; i++) {
                res += matrix[i][k++];
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};

int main() {
    // Disable standard input and output synchronization for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        string encodedText;
        int rows;
        cin.ignore(); 
        getline(cin >> ws, encodedText);  
        
        cin >> rows;

        string result = sol.decodeCiphertext(encodedText.substr(1, encodedText.length() - 2), rows);
        cout << result << "\n";
    }
    
    return 0;
}