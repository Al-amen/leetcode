class Solution:
    def maximum69Number (self, num: int) -> int:
       

        digits = list(str(num))
        for i in range(len(digits)):
            if digits[i] == "6":  # Corrected: Compare the digit at index i
                digits[i] = "9"
                break  # Stop after the first replacement


        return int(''.join(digits))
        
        
            

