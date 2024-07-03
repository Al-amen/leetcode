class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
       
        if(n <=4) {
            return 0;
        }

         int threeLarget = nums[n-4] - nums[0];
         int threeSmallest = nums[n-1]-nums[3];
         int oneLargestOneTwoSmallest = nums[n-2] - nums[2];
         int oneSmallestTwoLargest = nums[n-3]-nums[1];

         int mn = min(min(threeLarget,threeSmallest ),min(oneLargestOneTwoSmallest,oneSmallestTwoLargest )) ;
        

       

        return mn;

        

    
    }
};