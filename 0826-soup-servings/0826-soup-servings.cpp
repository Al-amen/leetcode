class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; // large-n shortcut

        int y = (n + 24) / 25; // ceil(n/25)
        vector<vector<double>> dp(y + 1, vector<double>(y + 1, 0.0));

        // base cases
        for (int a = 0; a <= y; ++a) {
            for (int b = 0; b <= y; ++b) {
                if (a == 0 && b == 0) dp[a][b] = 0.5;
                else if (a == 0) dp[a][b] = 1.0;
                else if (b == 0) dp[a][b] = 0.0;
                else {
                    double v1 = dp[max(0, a - 4)][b];
                    double v2 = dp[max(0, a - 3)][max(0, b - 1)];
                    double v3 = dp[max(0, a - 2)][max(0, b - 2)];
                    double v4 = dp[max(0, a - 1)][max(0, b - 3)];
                    dp[a][b] = 0.25 * (v1 + v2 + v3 + v4);
                }
            }
        }

        return dp[y][y];
    }
};
