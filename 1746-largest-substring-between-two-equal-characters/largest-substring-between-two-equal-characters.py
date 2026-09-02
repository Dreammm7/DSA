class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        first_idx = {}
        max_len = -1
        
        for i, char in enumerate(s):
            if char in first_idx:
                max_len = max(max_len, i - first_idx[char] - 1)
            else:
                first_idx[char] = i
                
        return max_len
        