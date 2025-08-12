class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                // destroy smaller positive asteroids
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                // if same size, destroy both
                if (!st.empty() && st.back() > 0 && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                // if stack is empty OR top is negative, push current asteroid
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
