class Solution {
public:
    int dfs(int node, string &colors, vector<vector<int>> &adj, vector<vector<int>> &count, vector<int> & vis) {
        if(!vis[node]) {
            vis[node] = 1;
            for(int next : adj[node]) {
                if(dfs(next,colors,adj,count,vis) == INT_MAX) {
                    return INT_MAX;
                }
                for(int c = 0 ; c < 26; c++) {
                    count[node][c] = max(count[node][c], count[next][c]);
                }

            }
            count[node][colors[node] - 'a']++;
            vis[node] = 2;
        }
        return vis[node] == 2 ? count[node][colors[node]-'a'] : INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n),count(n,vector<int>(26));
        vector<int>vis(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);

        }
        int ans = 0;
        for(int i = 0; i < n && ans != INT_MAX; i++) {
            ans = max(ans,dfs(i,colors,adj,count,vis));
        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};