#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Robot {
        int pos;
        int val;
        char dir;
        int idx;
    };

   public:
    vector<Robot> arr(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots(n);

        for (int i = 0; i < n; ++i) {
            robots[i] = {positions[i], healths[i], directions[i], i};
        }

        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        return robots;
    }

    vector<Robot> Collision(vector<Robot>& robots) {
        stack<int> st;  // store indices

        int n = robots.size();

        for (int i = 0; i < n; i++) {
            if (robots[i].dir == 'R') {
                st.push(i);
            } else {
                // current is 'L'
                while (!st.empty() && robots[st.top()].dir == 'R' && robots[i].val > 0) {
                    int j = st.top();  // index of previous R

                    if (robots[j].val < robots[i].val) {
                        st.pop();
                        robots[i].val--;    // L loses 1 health
                        robots[j].val = 0;  // R dies
                    } else if (robots[j].val > robots[i].val) {
                        robots[j].val--;    // R loses 1 health
                        robots[i].val = 0;  // L dies
                        break;
                    } else {
                        // equal
                        robots[j].val = 0;
                        robots[i].val = 0;
                        st.pop();
                        break;
                    }
                }

                // if L survived, it should stay
                if (robots[i].val > 0) {
                    st.push(i);
                }
            }
        }

        // collect survivors
        vector<Robot> res;
        for (int i = 0; i < n; i++) {
            if (robots[i].val > 0) {
                res.push_back(robots[i]);
            }
        }

        return res;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths,
                                      string directions) {
        vector<Robot> robots = arr(positions, healths, directions);
        vector<Robot> alive_rob = Collision(robots);

        sort(alive_rob.begin(), alive_rob.end(), [](auto& a, auto& b) { return a.idx < b.idx; });

        vector<int> result;
        for (auto& r : alive_rob) {
            result.push_back(r.val);
        }

        return result;
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
        int n;
        cin >> n;
        vector<int> positions(n), healths(n);
        string directions;
        for (int i = 0; i < n; ++i) {
            cin >> positions[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> healths[i];
        }
        cin >> directions;

        vector<int> result = sol.survivedRobotsHealths(positions, healths, directions);
        cout << "[";
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << ((i < result.size() - 1) ? ", " : "");
        }
    }

    return 0;
}