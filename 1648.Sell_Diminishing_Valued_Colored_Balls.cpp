class Solution {
public:
    int maxProfit(vector<int>& inv, int orders) {
    long res = 0, colors = 1;
    sort(begin(inv), end(inv)); // Sort inventory in ascending order
    for (int i = inv.size() - 1; i >= 0 && orders > 0; --i, ++colors) {
        long cur = inv[i], prev = i > 0 ? inv[i - 1] : 0; // Current and previous inventory counts
        
        // Calculate how many balls we can sell in this round
        long rounds = min(orders / colors, cur - prev);
        
        // Deduct the sold balls from orders
        orders -= rounds * colors;
        
        // Calculate the profit contribution from selling `rounds` balls of current color
        res = (res + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % 1000000007;
        
        // If we can't exhaust all `colors` rounds, sell the remaining orders at current price
        if (cur - prev > rounds) {
            res = (res + orders * (cur - rounds)) % 1000000007;
            break;
        }
    }
    return res;
}

   
        

};
