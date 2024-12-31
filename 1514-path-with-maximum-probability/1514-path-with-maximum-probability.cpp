class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int  E = edges.size();
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
             adj[u].push_back({v,w});
             adj[v].push_back({u,w});
        }

          
         priority_queue<pair<double,int>>pq;
         pq.push({1.0,start_node});
         vector<double>success(n,-1.0);

         while(!pq.empty()){
            int node = pq.top().second;
            double w = pq.top().first;
            pq.pop();
            for(auto it : adj[node]) {
                int u = it.first;
                if(w * it.second > success[u]) {
                    success[u] = w * it.second;
                    pq.push({it.second,u});
                }
            }
         }
         if(success[end_node] == -1.0) {
            return 0;
         }
         else {
            return success[end_node];
         }

        
    }
};