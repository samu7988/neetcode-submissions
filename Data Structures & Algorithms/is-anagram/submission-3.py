from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp = defaultdict(int)                            # auto-initializes missing keys to 0
        
        if len(s) != len(t):
            return False
        
        for i in range(len(s)):
            mp[s[i]] += 1                               # ✅ no .get() needed!
        
        for i in range(len(t)):
            if t[i] in mp:
                mp[t[i]] -= 1
            if t[i] in mp and mp[t[i]] == 0:            # check membership first
                del mp[t[i]]
        
        if not mp:
            return True
        return False