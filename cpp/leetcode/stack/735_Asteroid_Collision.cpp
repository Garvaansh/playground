#include <bits/stdc++.h>
using namespace std; 

/** Asteroid Collision
 * ? Simulates asteroid collisions, returns surviving asteroids in order
 * ! Uses stack for right-moving asteroids, handles left-moving collisions by popping smaller ones
 * ! Time: O(n) amortized (each asteroid pushed/popped at most once), Space: O(n)
 */

class Solution {
public:
    //* Main: process each asteroid, use stack to simulate collisions
    vector<int> asteroidCollision(vector<int>& asteroids) {
      stack<int> st;
      for(int i = 0; i < asteroids.size(); i++) {
        //* Positive (right-moving): push to stack
          if(asteroids[i] > 0) st.push(asteroids[i]);
          else {
            //* Negative (left-moving): pop smaller right-moving asteroids
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) st.pop();
            //* If equal size, both destroy
            if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
            //* Else, push this left-moving asteroid
            else if (st.empty() || st.top() < 0) st.push(asteroids[i]);
          }
        }
        //* Pop stack to result vector, reverse for correct order
        vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
          res[i] = st.top();
          st.pop();
        }
        return (res.size() > 0) ? res : vector<int>{};
  }
};


int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> asteroids(n);
    for(int i = 0; i < n; i++) cin >> asteroids[i];
    vector<int> res = Solution().asteroidCollision(asteroids);
    cout << "[";
    for (size_t i = 0; i < res.size(); ++i) {
      cout << res[i];
      if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }
    return 0;
}