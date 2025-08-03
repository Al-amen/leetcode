class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int maxFruits = 0;
        int left = 0, sum = 0;

        for (int right = 0; right < n; right++) {
            sum += fruits[right][1];

            // Shrink window from left if cost is too much
            while (left <= right && 
                   min(abs(startPos - fruits[left][0]), abs(startPos - fruits[right][0])) +
                   (fruits[right][0] - fruits[left][0]) > k) {
                sum -= fruits[left][1];
                left++;
            }

            maxFruits = max(maxFruits, sum);
        }

        return maxFruits;
    }
};
