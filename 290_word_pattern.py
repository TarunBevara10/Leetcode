class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        
        # Length mismatch
        if len(pattern) != len(words):
            return False
        
        char_to_word = {}
        word_to_char = {}
        
        for c, w in zip(pattern, words):
            
            # If c is mapped before, it must map to w
            if c in char_to_word and char_to_word[c] != w:
                return False
            
            # If w is mapped before, it must map to c
            if w in word_to_char and word_to_char[w] != c:
                return False
            
            # Create mapping both ways
            char_to_word[c] = w
            word_to_char[w] = c
        
        return True
