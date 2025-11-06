#include <bits/stdc++.h>
using namespace std; 

int num_of_moves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                return (abs(i - 2) + abs(j - 2));
            }
        }
    }
    return -1; 
}

int main() {
    vector<vector<int>> grid(5, vector<int>(5));
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }

    cout << num_of_moves(grid) << endl;

    return 0;
}