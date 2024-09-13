#include <vector>
using namespace std;

class Solution {
private:
    const int N = 3*10000 + 7;
    vector<long long> xorSum;

    void preCompute(const vector<int>& arr) {
        xorSum.resize(arr.size(), 0);
        if (!arr.empty()) {
            xorSum[0] = arr[0];
            for(int i = 1; i < arr.size(); i++) {
                xorSum[i] = xorSum[i-1] ^ arr[i];
            }
        }
    }

public:
    Solution() : xorSum(N, 0) {}  // Initialize xorSum with size N

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        preCompute(arr);
        int q = queries.size();
        vector<int> ans;
        for(int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int result;
            if (l == 0) {
                result = xorSum[r];
            } else {
                result = xorSum[r] ^ xorSum[l - 1];
            }
            ans.push_back(result);
        }
        return ans;
    }
};
