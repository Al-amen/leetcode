class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        from collections import defaultdict
        
        freq = defaultdict(int)
        i = 0
        max_len = 0
        
        for j in range(len(fruits)):
            # Expand the window by adding fruits[j]
            freq[fruits[j]] += 1
            
            # If we have more than 2 types, shrink from the left
            while len(freq) > 2:
                freq[fruits[i]] -= 1
                if freq[fruits[i]] == 0:
                    del freq[fruits[i]]
                i += 1
            
            # Update max window size
            max_len = max(max_len, j - i + 1)
        
        return max_len
