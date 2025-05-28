#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        
        // Build adjacency lists for both trees
        vector<vector<int>> tree1(n);
        for (const auto& edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }
        
        vector<vector<int>> tree2(m);
        for (const auto& edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }
        
        // Precompute distances for all nodes in tree1
        vector<vector<int>> dist1(n, vector<int>(n, -1));
        for (int i = 0; i < n; ++i) {
            queue<int> q;
            q.push(i);
            dist1[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : tree1[u]) {
                    if (dist1[i][v] == -1) {
                        dist1[i][v] = dist1[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        
        // Precompute distances for all nodes in tree2
        vector<vector<int>> dist2(m, vector<int>(m, -1));
        for (int i = 0; i < m; ++i) {
            queue<int> q;
            q.push(i);
            dist2[i][i] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : tree2[u]) {
                    if (dist2[i][v] == -1) {
                        dist2[i][v] = dist2[i][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        
        // For each node in tree2, compute the number of nodes within k-1 distance
        vector<int> max_tree2_counts(m, 0);
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int j = 0; j < m; ++j) {
                if (dist2[i][j] <= k - 1) {
                    count++;
                }
            }
            max_tree2_counts[i] = count;
        }
        int max_tree2 = *max_element(max_tree2_counts.begin(), max_tree2_counts.end());
        
        // For each node in tree1, compute the count within k distance, then add max_tree2
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (dist1[i][j] <= k) {
                    count++;
                }
            }
            res[i] = count + max_tree2;
        }
        
        return res;
    }
};