class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        i = 0                                            # int i = 0
        j = len(s) - 1                                   # int j = s.size() - 1
        
        while i <= j:                                    # while(i <= j)
            
            if s[i] == ' ' or not s[i].isalnum():        # if(s[i] == ' ' || isalnum(s[i]) == 0)
                i += 1                                   # i++
            elif s[j] == ' ' or not s[j].isalnum():      # else if(s[j] == ' ' || isalnum(s[j]) == 0)
                j -= 1                                   # j--
            elif s[i].lower() == s[j].lower():           # else if(tolower(s[i]) == tolower(s[j]))
                i += 1                                   # i++
                j -= 1                                   # j--
            else:
                return False                             # return false
        
        return True                                      # return true