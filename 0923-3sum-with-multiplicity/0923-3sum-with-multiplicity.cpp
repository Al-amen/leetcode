class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int mod = 1e9 + 7;
        unordered_map<int, long long> mp;
        for (int x : arr) mp[x]++;

        long long res = 0;
        for (auto& it1 : mp) {
            for (auto& it2 : mp) {
                int i = it1.first, j = it2.first;
                int k = target - i - j;
                if (!mp.count(k)) continue;

                // Ensure i <= j <= k to avoid overcounting
                if (i > j || j > k) continue;

                long long c1 = mp[i], c2 = mp[j], c3 = mp[k];

                if (i == j && j == k) {
                    // All equal
                    res += c1 * (c1 - 1) * (c1 - 2) / 6;
                }
                else if (i == j && j != k) {
                    // Two equal (i==j), one different (k)
                    res += c1 * (c1 - 1) / 2 * c3;
                }
                else if (i < j && j == k) {
                    // Two equal (j==k), one different (i)
                    res += c2 * (c2 - 1) / 2 * c1;
                }
                else if (i < j && j < k) {
                    // All distinct
                    res += c1 * c2 * c3;
                }
                // No other case allowed due to i <= j <= k
            }
        }

        return res % mod;
    }
};
