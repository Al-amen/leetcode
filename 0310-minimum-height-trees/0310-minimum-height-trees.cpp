class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    
        vector<int>res;
        if(n == 1) {
            res.push_back(0);
            return res;
        }
        vector<int>degree(n,0);
        vector<vector<int>>gp(n);
        queue<int>q;
       
        for(auto it: edges) {
                int u = it[0];
                int v = it[1];
                gp[u].push_back(v);
                gp[v].push_back(u);
                degree[u]++;
                degree[v]++;
        }

        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) {
                q.push(i);
            }
        }

        while(n>2) {
            int sz = q.size();
            n -= sz;

            while(sz > 0) {
            int u = q.front();      
            sz--;
            q.pop();
            for(auto it : gp[u]) {
                degree[it]--;
                if(degree[it] == 1) {
                    q.push(it);
                }
            }

         }
    }
        

        while(!q.empty()){
            int u = q.front();
            res.push_back(u);
            q.pop();
            for(auto it : gp[u]) {
                degree[it]--;
                if(degree[it] == 1) {
                    q.push(it);
                }
            }

        }
        return res;

    }
};