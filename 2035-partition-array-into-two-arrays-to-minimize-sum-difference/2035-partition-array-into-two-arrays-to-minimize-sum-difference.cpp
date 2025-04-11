class Solution {
public:
    int finder(set<int> &leftsum, set<int> &rightsum, int total) {
        int mn = INT_MAX;

        for (int ls : leftsum) {
            int target = total / 2 - ls;
            auto lb = rightsum.lower_bound(target);
            int other = 0;

            if (lb != rightsum.end()) {
                other = *lb;
            } else if (lb != rightsum.begin()) {
                lb--;
                other = *lb;
            }

            mn = min(mn, abs(total - 2 * (ls + other)));
        }

        return mn;
    }
   
    int minimumDifference(vector<int>& nums) {
        
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);

        int n1 = n/2;
        vector<int> left(nums.begin(),nums.begin()+n1);
        vector<int> right(nums.begin()+n1,nums.end());

        vector<set<int>> leftsum(n1 + 1), rightsum(n1 + 1);

       for (int i = 0; i < (1 << n1); i++) {
            int lsum = 0, rsum = 0, cnt = 0;
            for (int j = 0; j < n1; j++) {
                if (i & (1 << j)) {
                    lsum += left[j];
                    rsum += right[j];
                    cnt++;
                }
            }
            leftsum[cnt].insert(lsum);
            rightsum[cnt].insert(rsum);
        }
        int mn = INT_MAX;
        for (int i = 0; i <= n1; i++) {
            mn = min(mn, finder(leftsum[i], rightsum[n1 - i], total));
        }

        return mn;

       
         
    }
};
