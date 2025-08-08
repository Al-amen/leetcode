class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits; // No carry needed
            }
            digits[i] = 0; // Carry over
        }
        
        // If we reached here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
