class Solution {
  
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool>vis(numCourses);
        vector<int>ans;    
        vector<int>indegree(numCourses,0);
        queue<int>q;

        for(auto edge:prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
            indegree[u]++;
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
         
         while(!q.empty()){
            int u = q.front();
            ans.push_back(u);
            q.pop();
            
            for(auto adj: graph[u]) {
                indegree[adj]--;
                if(indegree[adj] == 0) {
                    q.push(adj);
                }
            }
         }
        
        
        return ans.size() == numCourses ? ans : vector<int>();


    }
};