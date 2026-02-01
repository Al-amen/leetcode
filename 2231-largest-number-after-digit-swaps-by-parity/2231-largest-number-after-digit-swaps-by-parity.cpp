class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p;
        priority_queue<int> q;
        string nums = to_string(num);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int digit = nums[i] - '0';

            if(digit%2) {
                p.push(digit);
            }
            else{
                q.push(digit);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = ans *10;
            if((nums[i] - '0')%2) {
                ans += p.top();
                p.pop();
            }
            else {
                ans += q.top();
                q.pop();
            }
        }
        return ans;

    }
};