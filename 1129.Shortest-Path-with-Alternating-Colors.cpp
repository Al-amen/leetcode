class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int, int>>> adj(n);  // Adjacency list

        // Add red edges
        for (auto &it : redEdges) {
            adj[it[0]].push_back({it[1], 0});
        }

        // Add blue edges
        for (auto &it : blueEdges) {
            adj[it[0]].push_back({it[1], 1});
        }

        vector<int> ans(n, -1);  // Result array to store the shortest path to each node
        vector<vector<bool>> visited(n, vector<bool>(2));  // Visited array to track visited nodes with color

        queue<vector<int>> q;
        q.push({0, 0, -1});  // Starting from node 0, step 0, no previous color
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int node = curr[0];
            int step = curr[1];
            int preColor = curr[2];
            
            // Traverse adjacent nodes
            for (auto &[neighbor, color] : adj[node]) {
                // Ensure it's not visited and the color alternates
                if (!visited[neighbor][color] && color != preColor) {
                    visited[neighbor][color] = true;
                    q.push({neighbor, step + 1, color});

                    // Update shortest path if it's the first time visiting
                    if (ans[neighbor] == -1) {
                        ans[neighbor] = step + 1;
                    }
                }
            }
        }
        return ans;
    }
};
