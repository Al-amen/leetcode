class Solution {
public:
    string triangleType(vector<int>& nums) {
        
        int a = nums[0] , b = nums[1] , c = nums[2];

        if(c >= a + b  || b >= a + c || a >= c + b)return "none";
        
        if(a == b && a == c && b == c) return "equilateral";
        else if(a == b || a == c || b == c)return "isosceles";
        else return "scalene" ;


        
    }
};