class Solution {
    private:
    bool dfs(vector<vector<int>>& graph, int src, vector<bool>& vis, vector<bool>& pathVis) {
       vis[src] = true;
       pathVis[src] = true;

       for (auto adjacent : graph[src]) {
           if (!vis[adjacent]) { // If the node is not visited, perform DFS.
               if (dfs(graph, adjacent, vis, pathVis)) {
                   return true;
               }
           } else if (pathVis[adjacent]) { // If the node is already in the current path, cycle detected.
               return true;
           }
       }

       pathVis[src] = false; // Remove the node from the current path after processing.
       return false;
   }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses, false);
        vector<bool>pathVis(numCourses, false);
        vector<vector<int>> graph(numCourses); 
        for (const auto& edge : prerequisites) {
            int u = edge[1]; 
            int v = edge[0];
            graph[u].push_back(v);
        }
        if(graph.size() == 0) return true;
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(dfs(graph,i,vis,pathVis)) {
                    return false;
                }
            }
        }
        return true;
    }
};