class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
       multimap<long long, long long> mp;
        
        for (int i = 0; i < nums.size(); i++) {
            long long mappedValue = 0;
            string original = to_string(nums[i]);
            
            // Convert each digit in the number to its mapped value
            for (int j = 0; j < original.size(); j++) {
                mappedValue = mappedValue * 10 + mapping[original[j] - '0'];
            }
            
            // Insert the mapped value and original number into the multimap
            mp.insert({mappedValue, nums[i]});
        }
        
        // Extract the sorted numbers based on the mapped values
        vector<int> sortedNums;
        for (auto it : mp) {
            sortedNums.push_back(it.second);
        }
        
        return sortedNums;
    }
};