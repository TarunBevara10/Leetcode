class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import Counter
        mag_count = Counter(magazine)
        note_count = Counter(ransomNote)

        for ch, freq in note_count.items():
            if mag_count[ch] < freq:
                return False
        return True
