#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int m = INT_MAX;
        unordered_map<int, int> freq;

        // Count frequencies from both baskets and track the smallest item
        for (int b1 : basket1) {
            freq[b1]++;
            m = min(m, b1);
        }
        for (int b2 : basket2) {
            freq[b2]--;
            m = min(m, b2);
        }

        vector<int> toSwap;

        // If any item occurs odd number of times in total, it's impossible
        for (auto& [item, count] : freq) {
            if (count % 2 != 0) return -1;
            // Add only extra items that need to be swapped
            for (int i = 0; i < abs(count) / 2; ++i) {
                toSwap.push_back(item);
            }
        }

        // Only half of toSwap need to be considered for actual cost
        // Sort to pick the smallest ones (cheapest to swap)
        sort(toSwap.begin(), toSwap.end());

        long long cost = 0;
        int n = toSwap.size() / 2;

        for (int i = 0; i < n; ++i) {
            cost += min(2 * m, toSwap[i]);
        }

        return cost;
    }
};
