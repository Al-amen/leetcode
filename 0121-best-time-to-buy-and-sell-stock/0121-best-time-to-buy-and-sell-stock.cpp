class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int max_profit = 0;
        for(int i = 0; i < n; i++) {
            max_profit = max(max_profit,prices[i]-mini);
            mini = min(mini,prices[i]);
        }

        return max_profit;
    }
};