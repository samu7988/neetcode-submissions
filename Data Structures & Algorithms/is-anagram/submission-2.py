class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = {}
        
        if len(s) != len(t):
            return False
        
        # count chars in s
        for ch in s:
            if ch in mp:
                mp[ch] += 1
            else:
                mp[ch] = 1
        
        # decrement counts using t
        for ch in t:
            if ch in mp:
                mp[ch] -= 1
                if mp[ch] == 0:
                    del mp[ch]
        
        return not mp