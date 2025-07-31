class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
         unordered_set<int> all_possible_or;
        unordered_set<int> or_ending_at_prev;
        unordered_set<int> or_ending_here;

        for(int i=0;i<arr.size();++i){
            or_ending_here.clear();
            or_ending_here.insert(arr[i]);

            for(int val: or_ending_at_prev)
                or_ending_here.insert(val | arr[i]);

            all_possible_or.insert(or_ending_here.begin(),or_ending_here.end());
            or_ending_at_prev = or_ending_here;
        }
        return all_possible_or.size();
    }
};