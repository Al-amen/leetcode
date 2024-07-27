class Solution {
    void FlodWarshall(vector<vector<long long>> &adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i = 0 ; i < original.size(); i++) {
            int s = original[i] - 'a';
            int t = changed[i] - 'a';
            adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if (adjMatrix[i][k] < LLONG_MAX && adjMatrix[k][j] < LLONG_MAX) {
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                    }
                }
            }
        }
    }

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.length() != target.length()) {
            return -1;
        }

        vector<vector<long long>> adjMatrix(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < 26; ++i) {
            adjMatrix[i][i] = 0; // Distance to itself is zero
        }

        FlodWarshall(adjMatrix, original, changed, cost);

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] != target[i]) {
                int s = source[i] - 'a';
                int t = target[i] - 'a';
                if (adjMatrix[s][t] == LLONG_MAX) {
                    return -1;
                }
                ans += adjMatrix[s][t];
            }
        }
        return ans;
    }
};
