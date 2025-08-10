class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st; // stores indices
        int water = 0;

        for (int i = 0; i < n; i++) {
            // While the current bar is taller than the bar at the top of the stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // no left boundary

                int distance = i - st.top() - 1; // width between boundaries
                int bounded_height = min(height[i], height[st.top()]) - height[top];

                water += distance * bounded_height;
            }
            st.push(i);
        }

        return water;
    }
};
