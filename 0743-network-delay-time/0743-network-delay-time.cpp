class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
            
        }
        priority_queue< pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,k});
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            for(auto &it : adj[node]){
                int next_node = it.first;
                int w = it.second;
                if(w + time < dist[next_node]) {
                    dist[next_node] = w + time;
                    pq.push({dist[next_node],next_node});
                }
            }
            

        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};