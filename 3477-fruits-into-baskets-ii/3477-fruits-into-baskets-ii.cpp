class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

         vector<int>mark(n,-1);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j]) {
                    if(mark[j] == -1) {
                        mark[j] = 1;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(mark[i] == -1) cnt++;
        }
        return cnt;
        
    }
};