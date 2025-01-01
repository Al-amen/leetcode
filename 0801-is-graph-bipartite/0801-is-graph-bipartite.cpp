class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int>color(n,-1);
       for(int st  = 0; st < n; st++) {
            if(color[st] == -1) {
                queue<int>q;
                q.push(st);
                color[0] = 0;
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]) {
                        if(color[it] == -1) {
                            color[it] = (~color[node]);
                            q.push(it);
                        }
                        if(color[it] == color[node]) {
                            return false;
                        }
                    }
                }
                

            }
                


       }
       return true;
        
    }

};