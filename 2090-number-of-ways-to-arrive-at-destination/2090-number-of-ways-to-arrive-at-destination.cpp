class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1'000'000'007;

        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }


        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX); 
        vector<int> ways(n, 0);               

       
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0); 

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

           
            if (d > dist[u]) continue;

         
            for (auto& [v, time] : graph[u]) {
                long long newDist = d + time;

         
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.emplace(newDist, v);
                } else if (newDist == dist[v]) {

                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
