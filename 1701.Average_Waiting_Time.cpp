class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double total_arival = 0;
        double waiting_time = 0;
        total_arival += customers[0][0] + customers[0][1];
        waiting_time += total_arival - customers[0][0];
        for(int i = 1; i <n; i++) {
            if(customers[i][0]<=total_arival) {
                total_arival += customers[i][1];
                waiting_time += total_arival - customers[i][0];
            }
            else {
                total_arival = customers[i][0] + customers[i][1];
                waiting_time += total_arival - customers[i][0];
            }
        }
        return waiting_time/(double)n;
        
    }
};
