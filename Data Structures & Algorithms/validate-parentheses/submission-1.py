class Solution:
    def isValid(self, s: str) -> bool:
        
        st = []
        
        if len(s) % 2 != 0:
            return False
        
        for ch in s:
            
            if ch in '([{':                              # opening bracket
                st.append(ch)
            
            elif ch in ')]}':                            # closing bracket
                if not st:                               # ✅ Pythonic empty check
                    return False
                
                res = st.pop()                           # peek + pop in one step
                
                if ch == ')' and res != '(':
                    return False
                if ch == ']' and res != '[':
                    return False
                if ch == '}' and res != '{':
                    return False
        
        return not st                                    # ✅ True if empty, False otherwise