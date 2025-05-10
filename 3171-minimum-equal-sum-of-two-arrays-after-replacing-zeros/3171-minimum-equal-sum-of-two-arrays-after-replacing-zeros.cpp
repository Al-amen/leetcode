class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero_one = 0;
        int zero_two = 0;
        long long sum1 = 0, sum2 = 0;
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i]==0)zero_one++;
            sum1 += nums1[i];
        }

         for(int i = 0; i < nums2.size(); i++) {
            if(nums2[i]==0)zero_two++;
            sum2 += nums2[i];
        }

        sum1 += zero_one;
        sum2 += zero_two;

       if(!zero_one && sum2 > sum1 || !zero_two && sum1 > sum2)return -1;
       else return max(sum1,sum2);
       
       


        
    }
};