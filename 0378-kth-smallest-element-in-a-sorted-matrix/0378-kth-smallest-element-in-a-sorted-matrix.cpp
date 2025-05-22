class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int n = matrix.size();
        for(int i = 0; i< n ; i++) {
            for(int j = 0; j <n ; j++) {
                min_heap.push(matrix[i][j]);
            }
        }
        k--;
        while(k--) {
            min_heap.pop();
        }
        return min_heap.top();
        
    }
};