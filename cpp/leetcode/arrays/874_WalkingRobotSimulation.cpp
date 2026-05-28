#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Build the obstacles set
        unordered_set<string> obs;

        for (auto& o : obstacles) {
            obs.insert(to_string(o[0]) + "_" + to_string(o[1]));
        }

        // Build the direction map
        vector<vector<int>> directions{
              {0, 1},   // North
              {1, 0},   // East
              {0, -1},  // South
              {-1, 0}   // West
        };

        int currDir = 0;  // start at North

        int max_dis = 0;
        int x = 0, y = 0;  // Starting position
        for (int i = 0; i < commands.size(); i++) {
            // Handle left turn
            if (commands[i] == -2) currDir = (currDir + 4 - 1) % 4;
            // Handle right turn
            else if (commands[i] == -1)
                currDir = (currDir + 4 + 1) % 4;
            // Handle move forward
            else {
                for (int step = 0; step < commands[i]; step++) {
                    int nX = x + directions[currDir][0];
                    int nY = y + directions[currDir][1];

                    // check for obstacle
                    if (obs.count(to_string(nX) + "_" + to_string(nY))) {
                        break;  // stop moving if there's an obstacle
                    }

                    x = nX;
                    y = nY;
                }
                max_dis = max(max_dis, x * x + y * y);
            }
        }

        return max_dis;
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
        int n, m;
        cin >> n >> m;

        vector<int> commands(n);
        for (int i = 0; i < n; ++i) {
            cin >> commands[i];
        }

        vector<vector<int>> obstacles(m, vector<int>(2));
        for (int i = 0; i < m; ++i) {
            cin >> obstacles[i][0] >> obstacles[i][1];
        }

        int result = sol.robotSim(commands, obstacles);
        cout << result << "\n";
    }

    return 0;
}