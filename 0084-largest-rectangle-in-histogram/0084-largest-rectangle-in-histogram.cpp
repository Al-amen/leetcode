#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> preMin(n, 0);  // previous smaller index
        vector<int> nextMin(n, 0); // next smaller index
        stack<int> st;

        // Next smaller element to the right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nextMin[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous smaller element to the left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            preMin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int width = nextMin[i] - preMin[i] - 1;
            max_area = max(max_area, width * heights[i]);
        }

        return max_area;
    }
};
