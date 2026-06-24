from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        mp = defaultdict(list)                            # auto-creates empty list
        
        for s in strs:
            key = ''.join(sorted(s))                      # sorted chars as key
            mp[key].append(s)                             # ✅ no if/else needed!
        
        return list(mp.values())