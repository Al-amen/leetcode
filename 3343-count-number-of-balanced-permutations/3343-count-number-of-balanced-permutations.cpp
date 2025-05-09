class Solution {
    const int MOD = 1e9 + 7;
    const int N = 80;
    vector<long long> fact, invFact;

public:
    long long modInverse(long long x) {
        return modPow(x, MOD - 2);
    }

    long long modPow(long long a, long long b) {
        long long r = 1;
        while (b > 0) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

    void preComputeFactorial(int N) {
        fact.resize(N + 1);
        invFact.resize(N + 1);
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
        invFact[N] = modInverse(fact[N]);
        for (int i = N - 1; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long solve(int pos, int n, int taken, int sum, vector<int>& digits, vector<vector<vector<long long>>>& dp) {
        if (taken == 0 && sum == 0) return 1;
        if (pos == n || taken < 0 || sum < 0) return 0;
        if (dp[pos][taken][sum] != -1) return dp[pos][taken][sum];

        long long res = solve(pos + 1, n, taken, sum, digits, dp) + 
                        solve(pos + 1, n, taken - 1, sum - digits[pos], digits, dp);

        return dp[pos][taken][sum] = res % MOD;
    }

    int countBalancedPermutations(string s) {
        int n = s.size(), totalSum = 0;
        vector<int> digits(n);

        for (int i = 0; i < n; i++) {
            digits[i] = s[i] - '0';
            totalSum += digits[i];
        }

        if (totalSum % 2 != 0) return 0;

        int target = totalSum / 2;
        int evens = n / 2;

        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(evens + 1, vector<long long>(target + 1, -1)));

        preComputeFactorial(n);

        long long waysToChoose = solve(0, n, evens, target, digits, dp);

        long long ans = waysToChoose * fact[evens] % MOD * fact[n - evens] % MOD;

        vector<int> freq(10);
        for (char c : s) freq[c - '0']++;
        for (int f : freq) ans = ans * invFact[f] % MOD;

        return ans;
    }
};
