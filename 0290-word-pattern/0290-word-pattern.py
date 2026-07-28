class Solution:
    # 2. Word Pattern (LeetCode 290)
    def wordPattern(self, pattern: str, s: str) -> bool:
        # Split the string into individual words
        words = s.split()
        
        # If the number of characters in pattern doesn't match the number of words, return False
        if len(pattern) != len(words):
            return False
            
        # Two dictionaries to maintain a bi-directional mapping between pattern chars and words
        char_to_word = {}
        word_to_char = {}
        
        for c, w in zip(pattern, words):
            # Check for conflict in character-to-word mapping
            if c in char_to_word and char_to_word[c] != w:
                return False
            # Check for conflict in word-to-character mapping
            if w in word_to_char and word_to_char[w] != c:
                return False
                
            # Establish the mapping
            char_to_word[c] = w
            word_to_char[w] = c
            
        # Return True if all mappings are consistent
        return True