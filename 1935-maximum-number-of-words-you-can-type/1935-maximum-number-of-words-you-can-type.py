class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(' ')
        broken_set = set(brokenLetters)  # Convert to set for O(1) lookup
        
        count = 0
        
        for word in words:
            # Check if this word contains any broken letters
            can_be_typed = True
            for char in word:
                if char in broken_set:
                    can_be_typed = False
                    break
            
            if can_be_typed:
                count += 1
        
        return count
