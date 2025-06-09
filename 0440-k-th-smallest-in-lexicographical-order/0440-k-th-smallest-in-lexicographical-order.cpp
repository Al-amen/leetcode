class Solution {
public:
    int countSteps(long curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(n, last) - first + 1; 
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr = 1; 
        k--;  
        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {  
                curr++;  
                k -= steps;  
            } else {  
                curr *= 10;  
                k--;  
            }
        }

        return curr;
    }
};